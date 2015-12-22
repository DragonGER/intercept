#include "config.hpp"
#include "client\pointers.hpp"
#include "common_helpers.hpp"

namespace intercept {
    namespace sqf {

        std::vector<config> config_hierarchy(const config &config_entry_) {
            game_value output = host::functions.invoke_raw_unary(client::__sqf::unary__confighierarchy__config__ret__array, config_entry_);
            return __helpers::__convert_to_configs_vector(output);
        }

        std::string config_name(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__configname__config__ret__string, config_entry_));
        }

        std::vector<config> config_properties(const config &config_entry, const std::string& condition_ = "true", bool inherit = true) {
            game_value array_entry({
                config_entry,
                condition_,
                inherit
            });
            game_value output = host::functions.invoke_raw_unary(client::__sqf::unary__configproperties__array__ret__array, array_entry);
            return __helpers::__convert_to_configs_vector(output);
        }

        std::string config_source_mod(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__configsourcemod__config__ret__string, config_entry_));
        }

        std::vector<std::string> config_source_mod_list(const config &config_entry_) {
            game_value output = host::functions.invoke_raw_unary(client::__sqf::unary__configsourcemodlist__config__ret__array, config_entry_);
            return __helpers::__convert_to_strings_vector(output);
        }

        float count(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__count__config__ret__scalar, config_entry_));
        }

        //std::vector<game_value> get_array(const config &config_entry_) {
        // TODO implement
        //}

            config get_mission_config(const std::string& value_) {
            return config(host::functions.invoke_raw_unary(client::__sqf::unary__getmissionconfig__string__ret__config, value_));
        }

        float get_number(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__getnumber__config__ret__scalar, config_entry_));
        }

        std::string get_text(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__gettext__config__ret__string, config_entry_));
        }

        config inherits_from(const config &config_entry_) {
            return config(host::functions.invoke_raw_unary(client::__sqf::unary__inheritsfrom__config__ret__config, config_entry_));
        }

        bool is_array(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isarray__config__ret__bool, config_entry_));
        }

        bool is_class(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isclass__config__ret__bool, config_entry_));
        }

        bool is_null(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnull__config__ret__bool, config_entry_));
        }

        bool is_number(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__isnumber__config__ret__bool, config_entry_));
        }

        bool is_text(const config &config_entry_) {
            return game_value(host::functions.invoke_raw_unary(client::__sqf::unary__istext__config__ret__bool, config_entry_));
        }

        std::vector<std::string> config_classes(const std::string& value_, config a_config_) {
            game_value output = host::functions.invoke_raw_binary(client::__sqf::binary__configclasses__string__config__ret__array, value_, a_config_);
            return __helpers::__convert_to_strings_vector(output);
        }

        void load_overlay(const control &a_control_, config a_config_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__loadoverlay__control__config__ret__nothing, a_control_, a_config_);
        }

        void new_overlay(const control &a_control_, config a_config_) {
            host::functions.invoke_raw_binary(client::__sqf::binary__newoverlay__control__config__ret__nothing, a_control_, a_config_);
        }
            
        config select(const config &a_config_, float a_number_) {
            return config(host::functions.invoke_raw_binary(client::__sqf::binary__select__config__scalar__ret__config, a_config_, a_number_));
        }

        config campaign_config_file() {
            return config(host::functions.invoke_raw_nular(client::__sqf::nular__campaignconfigfile__ret__config));
        }

        config config_file() {
            return config(host::functions.invoke_raw_nular(client::__sqf::nular__configfile__ret__config));
        }

        config config_null() {
            return config(host::functions.invoke_raw_nular(client::__sqf::nular__confignull__ret__config));
        }

        config mission_config_file() {
            return config(host::functions.invoke_raw_nular(client::__sqf::nular__missionconfigfile__ret__config));
        }

    }
}
