
#ifndef CLIENT_SERVER_STRINGABLEMATRIX_H
#define CLIENT_SERVER_STRINGABLEMATRIX_H

#include "Stringable.h"

class StringableMatrix : public Stringable {
    string mat_data;
public:
    explicit StringableMatrix(string mat_data);
    string makeString() override;
};

#endif //CLIENT_SERVER_STRINGABLEMATRIX_H
