#include "decls/declproductionfilter.h"

#include <algorithm>
#include <cstring>

namespace {

void SortFilter(idList<idStr, 5>& filter) {
    if (filter.Num() <= 1) return;
    std::sort(filter.Ptr(), filter.Ptr() + filter.Num(),
        [](const idStr& left, const idStr& right) {
            return std::strcmp(left.c_str(), right.c_str()) < 0;
        });
}

} // namespace

idDeclInfoTemplate<idDeclProductionFilter>
    idDeclProductionFilter::resourceList(
        "productionfilter", "idDeclProductionFilter", "tdef");

idDeclProductionFilter::idDeclProductionFilter()
    : entityFilter(16), entityRenderModelFilter(16) {
}

idDeclProductionFilter::~idDeclProductionFilter() = default;

idDeclInfo* idDeclProductionFilter::GetDeclInfo() const {
    return &resourceList;
}

void idDeclProductionFilter::Parse(idParser* const parser) {
    idDeclTypeInfo::Parse(parser);
    if (resourceError != nullptr) return;
    SortFilter(entityFilter);
    SortFilter(entityRenderModelFilter);
}
