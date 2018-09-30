/*
 * Author: Hans Hohenfeld <hans.hohenfeld@posteo.de>
 * License: GNU GPLv3
 */

#include <algorithm>

#include "CompletionData.h"

struct vbc::CompletionData::CompletionDataD
{
    std::string infoPattern;
    Container words;
    Container::pointer current;
};

vbc::CompletionData::CompletionData(const ProgramOptions& options)
    : d(std::make_unique<CompletionDataD>())
{
    d->infoPattern = options.getInfoPattern();
}

vbc::CompletionData::~CompletionData() = default;

void vbc::CompletionData::createWord(const BibLine& line, const FileName& bibFile)
{
    std::cmatch match = line.getLastMatch();

    d->current = &d->words.emplace_back(match[2], bibFile, d->infoPattern);
    d->current->addToInfo("bibtype", match[1]);
}

void vbc::CompletionData::addToCurrent(const BibLine& line)
{
    std::cmatch match = line.getLastMatch();

    if(d->current) {
        d->current->addToInfo(match[1], match[2]);
    }
}

bool vbc::CompletionData::empty() const
{
    return d->words.empty();
}

void vbc::CompletionData::sort()
{
    std::sort(d->words.begin(), d->words.end());
}

void vbc::CompletionData::write(std::ostream& os) const
{
    os << "{'words': [";

    std::copy(d->words.begin(), d->words.end(),
            std::ostream_iterator<CompletionWord>(os, ", "));

    os << "]}";
}

std::ostream& vbc::operator<<(std::ostream& os, const CompletionData& cd)
{
    cd.write(os);
    return os;
}
