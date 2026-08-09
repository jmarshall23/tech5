
/*
==================================================================================
Equations to convert color values to luminance values using various ITU standards.
==================================================================================
*/

/*
==================================================================================
ITU HDR standard BT-709-5
EY? = 0.2126 ER? + 0.7152 EG? + 0.0722 EB 
www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.709-5-200204-I!!PDF-E.pdf

int float colorRGB;
out float luminance;
==================================================================================
*/
#template Luminance_BT709( luminance, colorRGB )
{
	const float3 ituBT709 = float3( 0.2126, 0.7152, 0.0722 );
	lumiancne = dot( colorRGB, ituBT709 );
}
#endtemplate

/*
==================================================================================
ITU HDR standard BT-601-6
EY ? = 0.299 ER ? + 0.587 EG ? + 0.114 EB
www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.601-6-200701-S!!PDF-E.pdf

int float colorRGB;
out float luminance;
==================================================================================
*/
#template Luminance_BT601( luminance, colorRGB )
{
	const float3 ituBT601 = float3( 0.299, 0.587, 0.114 );
	luminance = dot( colorRGB, ituBT601 );
}
#endtemplate
