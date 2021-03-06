/*
 * Copyright 2015 WebAssembly Community Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WASMINT_TYPETABLE_H
#define WASMINT_TYPETABLE_H

#include <string>
#include <cstdint>
#include <map>
#include "types/Type.h"
#include "ExceptionWithMessage.h"
#include "Utils.h"


namespace wasm_module {

    ExceptionMessage(UnknownLocalTypeCode)

    class TypeTable {

        std::map<uint32_t, std::string> typesByLocalTypeCode;

    public:
        TypeTable() {
        }

        void addType(uint32_t localTypeCode, std::string name) {
            typesByLocalTypeCode[localTypeCode] = name;
        }

        const Type* getType(uint32_t localTypeCode);

        std::string getTypeName(uint32_t localTypeCode) {
            auto result = typesByLocalTypeCode.find(localTypeCode);
            if (result == typesByLocalTypeCode.end()) {
                throw UnknownLocalTypeCode(std::to_string(localTypeCode));
            } else {
                return result->second;
            }
        }

        bool operator==(const TypeTable& other) const {
            return Utils::compareMaps(typesByLocalTypeCode, other.typesByLocalTypeCode);
        }
    };
}

#endif //WASMINT_TYPETABLE_H
