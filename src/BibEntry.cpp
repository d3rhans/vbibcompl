#include "BibEntry.h"

struct vbc::BibEntry::BibEntryD
{
    MapType data;
};

vbc::BibEntry::BibEntry(const ValueType& bibKey, const ValueType& bibType)
    : d(std::make_unique<BibEntryD>())
{
    const KeyType BIBKEY{"bibkey"};
    const KeyType BIBTYPE{"bibtype"};

    d->data.emplace(BIBKEY, bibKey);
    d->data.emplace(BIBTYPE, bibType);
}

vbc::BibEntry::~BibEntry() = default;

void vbc::BibEntry::addToken(const KeyType& key, const ValueType& value)
{
    d->data.emplace(key, value);
}

vbc::BibEntry::iterator vbc::BibEntry::begin()
{
    return d->data.begin();
}

vbc::BibEntry::const_iterator vbc::BibEntry::begin() const
{
    return d->data.begin();
}

vbc::BibEntry::const_iterator vbc::BibEntry::cbegin() const
{
    return d->data.cbegin();
}

vbc::BibEntry::iterator vbc::BibEntry::end()
{
    return d->data.end();
}

vbc::BibEntry::const_iterator vbc::BibEntry::end() const
{
    return d->data.end();
}

vbc::BibEntry::const_iterator vbc::BibEntry::cend() const
{
    return d->data.cend();
}
