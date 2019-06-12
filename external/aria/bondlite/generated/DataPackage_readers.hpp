//------------------------------------------------------------------------------
// This code was generated by a tool.
//
//   Tool : bondjson2cpp 2016.12.18.1
//   File : DataPackage.json
//
// Changes to this file may cause incorrect behavior and will be lost when
// the code is regenerated.
// <auto-generated />
//------------------------------------------------------------------------------

#pragma once
#include "BondConstTypes.hpp"

namespace bond_lite {

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::ExceptionInfo& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.Type)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.Message)) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadString(value.FullInfo)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::Pstn& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.PstnNumber)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.HashedPstn)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::Endpoint& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.EndpointValue)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.EndpointType)) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadString(value.HashedEndpoint)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::User& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.Username)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.Prefix)) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadString(value.UiVersion)) {
                    return false;
                }
                break;
            }

            case 4: {
                if (!reader.ReadString(value.Endpoint)) {
                    return false;
                }
                break;
            }

            case 5: {
                if (!reader.ReadString(value.EndpointType)) {
                    return false;
                }
                break;
            }

            case 6: {
                if (!Deserialize(reader, value.Pstn, false)) {
                    return false;
                }
                break;
            }

            case 7: {
                if (!Deserialize(reader, value.EndpointComposite, false)) {
                    return false;
                }
                break;
            }

            case 8: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.UserExtension[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 9: {
                if (!reader.ReadString(value.Email)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::UserV1& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.Username)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.Prefix)) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadString(value.UiVersion)) {
                    return false;
                }
                break;
            }

            case 4: {
                if (!reader.ReadString(value.Endpoint)) {
                    return false;
                }
                break;
            }

            case 5: {
                if (!reader.ReadString(value.EndpointType)) {
                    return false;
                }
                break;
            }

            case 6: {
                if (!Deserialize(reader, value.Pstn, false)) {
                    return false;
                }
                break;
            }

            case 7: {
                if (!Deserialize(reader, value.EndpointComposite, false)) {
                    return false;
                }
                break;
            }

            case 8: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.UserExtension[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::Conference& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.ConferenceUri)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.DomainName)) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadString(value.UriScheme)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::PII& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                static_assert(sizeof(value.ScrubType) == 4, "Invalid size of enum");
                int32_t item4;
                if (!reader.ReadInt32(item4)) {
                    return false;
                }
                value.ScrubType = static_cast< ::clienttelemetry::data::v3::PIIScrubber>(item4);
                break;
            }

            case 2: {
                static_assert(sizeof(value.Kind) == 4, "Invalid size of enum");
                int32_t item4;
                if (!reader.ReadInt32(item4)) {
                    return false;
                }
                value.Kind = static_cast< ::clienttelemetry::data::v3::PIIKind>(item4);
                break;
            }

            case 3: {
                if (!reader.ReadString(value.RawContent)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::Record& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.Id)) {
                    return false;
                }
                break;
            }

            case 2: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRING) {
                    return false;
                }
                value.Context.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!reader.ReadString(value.Context[i4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadInt64(value.Timestamp)) {
                    return false;
                }
                break;
            }

            case 4: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.ConfigurationIds[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 5: {
                if (!reader.ReadString(value.Type)) {
                    return false;
                }
                break;
            }

            case 6: {
                if (!reader.ReadString(value.EventType)) {
                    return false;
                }
                break;
            }

            case 7: {
                if (!reader.ReadInt32(value.ResultCode)) {
                    return false;
                }
                break;
            }

            case 8: {
                if (!reader.ReadString(value.ResultDetail)) {
                    return false;
                }
                break;
            }

            case 9: {
                if (!reader.ReadString(value.ResultValue)) {
                    return false;
                }
                break;
            }

            case 10: {
                if (!reader.ReadString(value.InitiatingUser)) {
                    return false;
                }
                break;
            }

            case 11: {
                if (!reader.ReadString(value.InitiatingUserEndpoint)) {
                    return false;
                }
                break;
            }

            case 12: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRING) {
                    return false;
                }
                value.TargetUsers.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!reader.ReadString(value.TargetUsers[i4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 13: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.Extension[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 14: {
                if (!reader.ReadInt64(value.SampleTimestamp)) {
                    return false;
                }
                break;
            }

            case 15: {
                if (!reader.ReadString(value.SampleRate)) {
                    return false;
                }
                break;
            }

            case 16: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_LIST) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    uint32_t size5;
                    uint8_t type5;
                    if (!reader.ReadContainerBegin(size5, type5)) {
                        return false;
                    }
                    if (type5 != BT_INT64) {
                        return false;
                    }
                    value.SamplingData[key4].resize(size5);
                    for (unsigned i5 = 0; i5 < size5; i5++) {
                        if (!reader.ReadInt64(value.SamplingData[key4][i5])) {
                            return false;
                        }
                    }
                    if (!reader.ReadContainerEnd()) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 17: {
                if (!reader.ReadString(value.InitiatingUiVersion)) {
                    return false;
                }
                break;
            }

            case 18: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.PstnNumbers[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 19: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.ContextIds[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 20: {
                if (!reader.ReadString(value.InitiatingUserEndpointType)) {
                    return false;
                }
                break;
            }

            case 21: {
                if (!Deserialize(reader, value.DeprecatedInitiatingUserComposite, false)) {
                    return false;
                }
                break;
            }

            case 22: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRUCT) {
                    return false;
                }
                value.DeprecatedTargetUsersComposite.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!Deserialize(reader, value.DeprecatedTargetUsersComposite[i4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 23: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRUCT) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!Deserialize(reader, value.PstnNumbersComposite[key4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 24: {
                static_assert(sizeof(value.RecordType) == 4, "Invalid size of enum");
                int32_t item4;
                if (!reader.ReadInt32(item4)) {
                    return false;
                }
                value.RecordType = static_cast< ::clienttelemetry::data::v3::RecordType>(item4);
                break;
            }

            case 25: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_INT64) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadInt64(value.ExtensionInt64[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 26: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_DOUBLE) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadDouble(value._reserved[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 28: {
                if (!Deserialize(reader, value.ConferenceComposite, false)) {
                    return false;
                }
                break;
            }

            case 29: {
                if (!Deserialize(reader, value.ExceptionInfo, false)) {
                    return false;
                }
                break;
            }

            case 30: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRUCT) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!Deserialize(reader, value.PIIExtensions[key4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 31: {
                if (!Deserialize(reader, value.InitiatingUserComposite, false)) {
                    return false;
                }
                break;
            }

            case 32: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRUCT) {
                    return false;
                }
                value.TargetUsersComposite.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!Deserialize(reader, value.TargetUsersComposite[i4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::DataPackage& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                if (!reader.ReadString(value.Type)) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadString(value.Source)) {
                    return false;
                }
                break;
            }

            case 3: {
                if (!reader.ReadString(value.Version)) {
                    return false;
                }
                break;
            }

            case 4: {
                uint32_t size4;
                uint8_t keyType4, valueType4;
                if (!reader.ReadMapContainerBegin(size4, keyType4, valueType4)) {
                    return false;
                }
                if (keyType4 != BT_STRING || valueType4 != BT_STRING) {
                    return false;
                }
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    std::string key4;
                    if (!reader.ReadString(key4)) {
                        return false;
                    }
                    if (!reader.ReadString(value.Ids[key4])) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 5: {
                if (!reader.ReadString(value.DataPackageId)) {
                    return false;
                }
                break;
            }

            case 6: {
                if (!reader.ReadInt64(value.Timestamp)) {
                    return false;
                }
                break;
            }

            case 7: {
                if (!reader.ReadInt32(value.SchemaVersion)) {
                    return false;
                }
                break;
            }

            case 8: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRUCT) {
                    return false;
                }
                value.Records.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!Deserialize(reader, value.Records[i4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 9: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRUCT) {
                    return false;
                }
                value.Receipts.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!Deserialize(reader, value.Receipts[i4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

template<typename TReader>
bool Deserialize(TReader& reader, ::clienttelemetry::data::v3::ClientToCollectorRequest& value, bool isBase)
{
    if (!reader.ReadStructBegin(isBase)) {
        return false;
    }

    uint8_t type;
    uint16_t id;
    for (;;) {
        if (!reader.ReadFieldBegin(type, id)) {
            return false;
        }

        if (type == BT_STOP || type == BT_STOP_BASE) {
            if (isBase != (type == BT_STOP_BASE)) {
                return false;
            }
            break;
        }

        switch (id) {
            case 1: {
                uint32_t size4;
                uint8_t type4;
                if (!reader.ReadContainerBegin(size4, type4)) {
                    return false;
                }
                if (type4 != BT_STRUCT) {
                    return false;
                }
                value.DataPackages.resize(size4);
                for (unsigned i4 = 0; i4 < size4; i4++) {
                    if (!Deserialize(reader, value.DataPackages[i4], false)) {
                        return false;
                    }
                }
                if (!reader.ReadContainerEnd()) {
                    return false;
                }
                break;
            }

            case 2: {
                if (!reader.ReadInt32(value.RequestRetryCount)) {
                    return false;
                }
                break;
            }

            default:
                return false;
        }

        if (!reader.ReadFieldEnd()) {
            return false;
        }
    }

    if (!reader.ReadStructEnd(isBase)) {
        return false;
    }

    return true;
}

} // namespace bond_lite
