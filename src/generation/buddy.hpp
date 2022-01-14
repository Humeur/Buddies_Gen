#pragma once

#include <list>
#include "../attribute/attribute.hpp"
#include <optional>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace buddy {

class Buddy {
    public:
        using value_type = std::pair<std::string, std::string>;
    private:
        std::list<value_type> attributes;
        std::list<std::pair<Image, Color>> layers;
        std::optional<HexColor> hairColor;
        bool containsAttribute(const value_type &attribute) const {
            for (auto &[key, value] : this->attributes) {
                if (key == attribute.first && value == attribute.second) {
                    return true;
                }
            }

            return false;
        }
    public:
        void addAttribute(const std::string &name, const std::string &value) {
            this->attributes.emplace_back(name, value);
        }

        [[nodiscard]] const std::list<std::pair<std::string, std::string>> &getAttributes() const {
            return this->attributes;
        }

        [[nodiscard]] const std::list<std::pair<Image, Color>> &getLayers() const {
            return this->layers;
        }

        void addLayer(const Image &image, const Color &color = WHITE) {
            this->layers.emplace_back(image, color);
        }

        void save(const int &id, Image &canvas) const {
            using namespace std;
            int offsetX = (id % 100) * 24;
            int offsetY = (id / 100) * 24;

            for (auto &[image, color] : this->layers) {
                canvas.merge(image, offsetX, offsetY, color);
            }

            EMPTY.copy(canvas, offsetX, offsetY);
            stringstream ss;
            ss << "out/images/" << id << ".png";
            EMPTY.save(ss.str().c_str());
            ss = stringstream();
            ss << "out/metadatas/" << id;
            ofstream meta(ss.str());
            ss << "yo" << std::endl;
            meta << "{\n";
            meta << "\t\"name\": \"Buddy #" << setw(4) << setfill('0') << id << "\",\n";
            meta << "\t\"external_url\": \"https://bdds.io\",\n";
            meta << "\t\"attributes\": [\n";
            for (auto itr = this->attributes.begin(); itr != this->attributes.end(); ) {
                meta << "\t\t{\n";
                meta << "\t\t\t\"trait_type\": \"" << itr->first << "\",\n";
                meta << "\t\t\t\"value\": \"" << itr->second << "\"\n";
                meta << "\t\t}";
                if (++itr != this->attributes.end()) {
                    meta << ",";
                }
                meta << '\n';
            }
            meta << "\t]\n";
            meta << '}';
        }

        void setHairColor(const HexColor &color) {
            this->hairColor = color;
        }

        [[nodiscard]] const std::optional<HexColor> getHairColor() const {
            return this->hairColor;
        }

        size_t hash() const {
            size_t hash = 31;
            std::hash<std::string> h;
            for (auto &[name, attr] : this->attributes) {
                hash ^= h(name) ^ h(attr);
                hash *= 31;
            }
            return hash;
        }

        bool operator==(const Buddy &other) const {
            if (this == &other) {
                return true;
            }

            if (this->attributes.size() != other.attributes.size()) {
                return false;
            }

            for (auto &attribute : other.attributes) {
                if (!containsAttribute(attribute)) {
                    return false;
                }
            }

            return true;
        }
};

};

template <>
struct std::hash<buddy::Buddy> {
    size_t operator()(const buddy::Buddy &buddy) const noexcept {
        return buddy.hash();
    }
};

template <>
struct std::equal_to<buddy::Buddy> {
    bool operator()(const buddy::Buddy &lhs, const buddy::Buddy &rhs) const noexcept {
        return lhs == rhs;
    }
};