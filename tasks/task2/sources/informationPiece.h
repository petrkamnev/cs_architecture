//
// Created by petrkamnev on 19.10.2021.
//

#ifndef AVS2_INFORMATIONPIECE_H
#define AVS2_INFORMATIONPIECE_H

#include <string>

class InformationPiece {
public:
    virtual std::string getTitle() = 0;

    virtual std::string getContent() = 0;

    virtual double getCharacteristic() = 0;

    virtual std::string getType() = 0;
};

#endif //AVS2_INFORMATIONPIECE_H
