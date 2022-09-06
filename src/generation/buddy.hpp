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
        using attribute = std::pair<std::string_view, std::string_view>;
        using layer = std::pair<const Image &, Color>;
    private:
        std::list<attribute> attributes;
        std::list<layer> layers;
        std::optional<ColorAttribute> hairColor;
        bool containsAttribute(const attribute &attribute) const {
            for (auto &[key, value] : this->attributes) {
                if (key == attribute.first && value == attribute.second) {
                    return true;
                }
            }

            return false;
        }
    public:
        void addAttribute(std::string_view name, std::string_view value) {
            this->attributes.emplace_back(name, value);
        }

        void addLayer(const Image &image, Color color = WHITE) {
            this->layers.emplace_back(image, color);
        }

        void save(const int &id, Image &canvas) const {
            using namespace std;
            int offsetX = (id % 100) * 24;
            int offsetY = (id / 100) * 24;

            for (auto &[image, color] : this->layers) {
                canvas.merge(image, offsetX, offsetY, color);
            }

            PLACEHOLDER.copy(canvas, offsetX, offsetY);
            stringstream ss;
            ss << "out/images/" << id << ".png";
            PLACEHOLDER.save(ss.str().c_str());
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

        void setHairColor(const ColorAttribute &color) {
            this->hairColor = color;
        }

        [[nodiscard]] const std::optional<ColorAttribute> getHairColor() const {
            return this->hairColor;
        }

        size_t hash() const {
            size_t hash = 31;
            std::hash<std::string_view> h;
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

            if (containsAttribute({type::ATTRIBUTE_NAME, type::JAR_ATTRIBUTE_VALUE})) {
                return false;
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

namespace std {

template <>
struct hash<buddy::Buddy> {
    size_t operator()(const buddy::Buddy &buddy) const noexcept {
        return buddy.hash();
    }
};

template <>
struct equal_to<buddy::Buddy> {
    bool operator()(const buddy::Buddy &lhs, const buddy::Buddy &rhs) const noexcept {
        return lhs == rhs;
    }
};

}
