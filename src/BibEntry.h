#ifndef BIBENTRY_H_
#define BIBENTRY_H_

#include <map>
#include <memory>
#include <string>

namespace vbc
{
    class BibEntry
    {
        private:
            struct BibEntryD;
            std::unique_ptr<BibEntryD> d;

        public:
            using KeyType   = std::string;
            using ValueType = std::string;
            using MapType   = std::map<KeyType, ValueType>;

            using iterator       = MapType::iterator;
            using const_iterator = MapType::const_iterator;

            BibEntry(const ValueType& bibKey, const ValueType& bibType);
            ~BibEntry();

            void addToken(const KeyType& key, const ValueType& value);

            iterator begin();
            const_iterator begin()  const;
            const_iterator cbegin() const;

            iterator end();
            const_iterator end()  const;
            const_iterator cend() const;
    };
}

#endif /* define BIBENTRY_H_ */
