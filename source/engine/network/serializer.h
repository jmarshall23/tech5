#pragma once

// Reconstructed from w:\tech5\engine\network\serializer.h.
// The recovered PDB fixes the field order; the decorated Hex-Rays methods
// fix the serialization surface and bit-level behavior.

#include "../sys/sys_types.h"
#include "../../shared/idlib/networking/bitmsg.h"
#include "../../shared/idlib/containers/list.h"
#include "../../shared/idlib/text/str.h"
#include "../../shared/idlib/text/atomicstring.h"
#include "../../shared/idlib/langdict.h"
#include "../../shared/idlib/math/random.h"
#include "../../shared/idlib/math/vector.h"
#include "../../shared/idlib/sys/sys_alloc.h"

#include <cassert>
#include <cstring>
#include <type_traits>

#define SERIALIZE_BOOL( ser, value ) ((value) = (ser).SerializeBoolNonRef(value))
#define SERIALIZE_ENUM( ser, value, type, maximum ) \
    ((value) = static_cast<type>((ser).SerializeUMaxNonRef(static_cast<int>(value), maximum)))

namespace tech5SerializerDetail {
ID_INLINE int BitsForInteger( uint32 value ) {
    int bits = 0;
    do {
        ++bits;
        value >>= 1;
    } while ( value != 0 );
    return bits;
}

template<typename T>
ID_INLINE void WriteRaw( idBitMsg & msg, const T & value ) {
    static_assert( std::is_trivially_copyable<T>::value, "raw serializer type" );
    const uint8 * bytes = reinterpret_cast<const uint8 *>( &value );
    for ( size_t index = 0; index < sizeof( T ); ++index ) {
        msg.WriteBits( bytes[index], 8 );
    }
}

template<typename T>
ID_INLINE void ReadRaw( const idBitMsg & msg, T & value ) {
    static_assert( std::is_trivially_copyable<T>::value, "raw serializer type" );
    uint8 * bytes = reinterpret_cast<uint8 *>( &value );
    for ( size_t index = 0; index < sizeof( T ); ++index ) {
        bytes[index] = static_cast<uint8>( msg.ReadBits( 8 ) );
    }
}
}

class idSerializer {
public:
    idSerializer( idBitMsg & message, bool isWriting )
        : writing( isWriting ), msg( &message ) {
    }

    bool IsReading() const { return !writing; }
    bool IsWriting() const { return writing; }
    idBitMsg & GetMsg() { return *msg; }
    const idBitMsg & GetMsg() const { return *msg; }

    void SerializeRange( int & value, int minimum, int maximum ) {
        const int bits = tech5SerializerDetail::BitsForInteger(
            static_cast<uint32>( maximum - minimum ) );
        if ( writing ) {
            msg->WriteBits( value - minimum, bits );
        } else {
            value = minimum + msg->ReadBits( bits );
        }
        assert( value >= minimum && value <= maximum );
    }

    void SerializeUMax( int & value, int maximum ) {
        value = SerializeUMaxNonRef( value, maximum );
    }

    int SerializeUMaxNonRef( int value, int maximum ) {
        const int bits = tech5SerializerDetail::BitsForInteger(
            static_cast<uint32>( maximum ) );
        if ( writing ) {
            msg->WriteBits( value, bits );
        } else {
            value = msg->ReadBits( bits );
        }
        assert( value >= 0 && value <= maximum );
        return value;
    }

    bool SerializeBoolNonRef( bool value ) {
        if ( writing ) {
            msg->WriteBits( value ? 1 : 0, 1 );
        } else {
            value = msg->ReadBits( 1 ) != 0;
        }
        return value;
    }

    void SerializeBytes( void * bytes, int count ) {
        uint8 * data = static_cast<uint8 *>( bytes );
        for ( int index = 0; index < count; ++index ) {
            Serialize( data[index] );
        }
    }

    void SerializeString( char * text, int bufferSize ) {
        if ( writing ) {
            msg->WriteString( text );
        } else {
            msg->ReadString( text, bufferSize );
        }
    }

    void SerializeString( idStr & text ) {
        if ( writing ) {
            msg->WriteString( text.c_str() );
        } else {
            msg->ReadString( text );
        }
    }

    void SerializeString( idAtomicString & text ) {
        if ( writing ) {
            msg->WriteString( text.c_str() );
        } else {
            idStr value;
            msg->ReadString( value );
            text.Set( value.c_str() );
        }
    }

    void SerializeString( idStrId & text ) {
        if ( writing ) {
            msg->WriteString( text.GetKey() );
        } else {
            idStr value;
            msg->ReadString( value );
            text.Set( value.c_str() );
        }
    }

    template<typename T>
    void Serialize( T *& value );

    template<typename T>
    void Serialize( const T *& value );

    void Serialize( int64 & value ) { SerializeRaw( value ); }
    void Serialize( uint64 & value ) { SerializeRaw( value ); }
    void Serialize( int32 & value ) { SerializeRaw( value ); }
    void Serialize( uint32 & value ) { SerializeRaw( value ); }
    void Serialize( int16 & value ) { SerializeRaw( value ); }
    void Serialize( uint16 & value ) { SerializeRaw( value ); }
    void Serialize( int8 & value ) { SerializeRaw( value ); }
    void Serialize( uint8 & value ) { SerializeRaw( value ); }
    void Serialize( float & value ) { SerializeRaw( value ); }
    void Serialize( bool & value ) { value = SerializeBoolNonRef( value ); }

    void Serialize( idRandom2 & value ) {
        uint32 seed = value.GetSeed();
        Serialize( seed );
        if ( IsReading() ) {
            value.SetSeed( seed );
        }
    }

    void Serialize( idVec2 & value ) { SerializeVector( value ); }
    void Serialize( idVec3 & value ) { SerializeVector( value ); }
    void Serialize( idVec4 & value ) { SerializeVector( value ); }
    void Serialize( idVec6 & value ) { SerializeVector( value ); }

    void Serialize( idMat3 & value ) {
        for ( int row = 0; row < 3; ++row ) {
            for ( int column = 0; column < 3; ++column ) {
                Serialize( value[row][column] );
            }
        }
    }

    void SerializeC( idMat3 & value ) { Serialize( value ); }
    void SerializeQ( idMat3 & value, int = 15 ) { Serialize( value ); }

    template<int maximum, int numBits>
    void SerializeQ( float & value ) {
        const float scale = static_cast<float>( ( 1u << ( numBits - 1 ) ) - 1u )
            / static_cast<float>( maximum );
        if ( writing ) {
            msg->WriteBits( static_cast<int>( value * scale ), -numBits );
        } else {
            value = static_cast<float>( msg->ReadBits( -numBits ) ) / scale;
        }
    }

    template<int maximum, int numBits>
    void SerializeUQ( float & value ) {
        if ( writing ) {
            msg->WriteQuantizedUFloat<maximum, numBits>( value );
        } else {
            value = msg->ReadQuantizedUFloat<maximum, numBits>();
        }
    }

    template<int maximum, int numBits>
    void SerializeQ( idVec3 & value ) {
        if ( writing ) {
            msg->WriteQuantizedVector<idVec3, maximum, numBits>( value );
        } else {
            msg->ReadQuantizedVector<idVec3, maximum, numBits>( value );
        }
    }

    void SerializeAngle( float & value ) {
        while ( value < 0.0f ) value += 360.0f;
        while ( value >= 360.0f ) value -= 360.0f;
        uint16 packed = static_cast<uint16>( value * ( 65536.0f / 360.0f ) );
        Serialize( packed );
        if ( IsReading() ) value = packed * ( 360.0f / 65536.0f );
    }

    void SerializeDelta( int32 & value, const int32 & base ) { SerializeDeltaRaw( value, base ); }
    void SerializeDelta( int16 & value, const int16 & base ) { SerializeDeltaRaw( value, base ); }
    void SerializeDelta( int8 & value, const int8 & base ) { SerializeDeltaRaw( value, base ); }
    void SerializeDelta( uint16 & value, const uint16 & base ) { SerializeDeltaRaw( value, base ); }
    void SerializeDelta( uint8 & value, const uint8 & base ) { SerializeDeltaRaw( value, base ); }
    void SerializeDelta( float & value, const float & base ) { SerializeDeltaRaw( value, base ); }

    void SerializePacked( int & value );
    void SerializeSPacked( int & value );

    template<typename T>
    void SerializeListElement( const idList<T *> & list, const T *& element ) {
        int index = -1;
        if ( writing && element != nullptr ) {
            for ( int i = 0; i < list.Num(); ++i ) {
                if ( list[i] == element ) {
                    index = i;
                    break;
                }
            }
        }
        SerializeRange( index, -1, list.Num() - 1 );
        if ( IsReading() ) {
            element = index >= 0 ? list[index] : nullptr;
        }
    }

    void SerializeCheckpoint( const char *, int ) {}
    void SanityCheck() const {}

private:
    template<typename T>
    void SerializeRaw( T & value ) {
        if ( writing ) {
            tech5SerializerDetail::WriteRaw( *msg, value );
        } else {
            tech5SerializerDetail::ReadRaw( *msg, value );
        }
    }

    template<typename T>
    void SerializeDeltaRaw( T & value, const T & base ) {
        bool changed = value != base;
        changed = SerializeBoolNonRef( changed );
        if ( changed ) {
            SerializeRaw( value );
        } else if ( IsReading() ) {
            value = base;
        }
    }

    template<typename T>
    void SerializeVector( T & value ) {
        for ( int index = 0; index < value.GetDimension(); ++index ) {
            Serialize( value[index] );
        }
    }

    // PDB-authoritative order for the Win32/Xbox 360 32-bit layout.
    bool writing;
    idBitMsg * msg;
};

struct idSerializerLog {
    struct logEntry_t {
        idStr typeName;
        idStr instanceName;
        int objID;
        int parent;
        int parentObjID;
        int start;
        int end;
        int startWriteBit;
        int endWriteBit;
    };

    struct compressionEntry_t {
        int objID;
        int csize;
    };

    idSerializerLog()
        : finalCompressedSize( 0 ), finalUncompressedSize( 0 ),
          fragmented( false ), lastEntry( -1 ), lastObjID( -1 ), refCount( 1 ) {
    }
    ~idSerializerLog() = default;

    void AddRef();
    void Release();
    int Find( int parentObjID, const char * typeName, const char * instanceName ) const;
    void AddCompressionLog( int objID, int compressedSize );

    idList<logEntry_t, 44> logEntries;
    idList<compressionEntry_t, 44> compressionEntries;
    int finalCompressedSize;
    int finalUncompressedSize;
    bool fragmented;
    int lastEntry;
    int lastObjID;
    int refCount;
};

ID_INLINE void idSerializer::SerializePacked( int & value ) {
    if ( writing ) {
        uint32 remaining = static_cast< uint32 >( value );
        do {
            const uint8 payload = static_cast< uint8 >( remaining & 0x7Fu );
            remaining >>= 7;
            msg->WriteBits( payload | ( remaining != 0 ? 0x80 : 0 ), 8 );
        } while ( remaining != 0 );
    } else {
        uint32 result = 0;
        int shift = 0;
        while ( shift < 32 ) {
            const uint8 packed = static_cast< uint8 >( msg->ReadBits( 8 ) );
            result |= static_cast< uint32 >( packed & 0x7F ) << shift;
            shift += 7;
            if ( ( packed & 0x80 ) == 0 ) {
                break;
            }
        }
        value = static_cast< int >( result );
    }
}

ID_INLINE void idSerializer::SerializeSPacked( int & value ) {
    int packed = writing
        ? static_cast< int >( ( static_cast< uint32 >( value ) << 1 ) ^ static_cast< uint32 >( value >> 31 ) )
        : 0;
    SerializePacked( packed );
    if ( !writing ) {
        value = static_cast< int >( ( static_cast< uint32 >( packed ) >> 1 ) ^
            static_cast< uint32 >( -static_cast< int >( packed & 1 ) ) );
    }
}

ID_INLINE void idSerializerLog::AddRef() {
    ++refCount;
}

ID_INLINE void idSerializerLog::Release() {
    if ( --refCount <= 0 ) {
        this->~idSerializerLog();
        Sys_Free( this );
    }
}

ID_INLINE int idSerializerLog::Find( int parentObjID, const char * typeName,
        const char * instanceName ) const {
    (void)instanceName; // The shipped RAGE body accepted but did not compare it.
    for ( int index = 0; index < logEntries.Num(); ++index ) {
        if ( logEntries[ index ].parentObjID == parentObjID &&
                _stricmp( logEntries[ index ].typeName.c_str(), typeName ) == 0 ) {
            return index;
        }
    }
    return -1;
}

ID_INLINE void idSerializerLog::AddCompressionLog( int objID, int compressedSize ) {
    if ( objID <= 0 || compressedSize <= 0 ) {
        return;
    }
    idScopedGlobalHeap globalHeap;
    compressionEntry_t * entry = compressionEntries.Alloc();
    if ( entry != NULL ) {
        entry->objID = objID;
        entry->csize = compressedSize;
    }
}

#if defined( _WIN32 ) && !defined( _WIN64 )
static_assert( sizeof( idSerializer ) == 8, "Recovered idSerializer ABI changed" );
#endif
