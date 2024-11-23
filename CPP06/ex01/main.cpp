#include "Serializer.hpp"

int main()
{
    Data originalData = {'A', 42, 3.14f};

    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << raw << std::endl;

    Data *deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &originalData)
    {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "charValue: " << deserializedData->c << std::endl;
        std::cout << "intValue: " << deserializedData->i << std::endl;
        std::cout << "floatValue: " << deserializedData->f << std::endl;
    }
    else
        std::cout << "Deserialization failed!" << std::endl;

    return 0;
}
