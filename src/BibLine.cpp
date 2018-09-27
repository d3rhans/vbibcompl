#include "BibLine.h"

struct vbc::BibLine::BibLineD
{
    LineType line;
};

vbc::BibLine::BibLine()
    : d(std::make_unique<BibLineD>())
{

}

vbc::BibLine::~BibLine() = default;

void vbc::BibLine::setLine(LineType&& line)
{
    d->line = line;
}

std::istream& vbc::operator>>(std::istream& is, BibLine& bl)
{
    BibLine::LineType line;

    std::getline(is, line);
    bl.setLine(std::move(line));

    return is;
}
