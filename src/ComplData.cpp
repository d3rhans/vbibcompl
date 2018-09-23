/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#include <algorithm>
#include <iterator>

#include "ComplData.h"

struct vbc::ComplData::ComplDataD
{
    Converter converter;
    std::vector<ComplWord> words;
};

vbc::ComplData::ComplData(const Converter& converter)
    : d(std::make_unique<ComplDataD>())
{
    d->converter = converter;
}

vbc::ComplData::~ComplData() = default;

void vbc::ComplData::addBibEntry(BibEntry& bibEntry)
{
    static ComplWord cw;

    if(!bibEntry.empty()) {
        d->converter.bibEntryToComplWord(bibEntry, cw);
        d->words.push_back(cw);
        bibEntry.clear();
    }
}

void vbc::ComplData::write(std::ostream& stream) const
{
    stream << "{'words': [";

    std::copy(d->words.begin(), d->words.end(),
            std::ostream_iterator<ComplWord>(stream, ", "));

    stream << "]}";
}

std::ostream& vbc::operator<<(std::ostream& stream, const ComplData& data)
{
    data.write(stream);
    return stream;
}
