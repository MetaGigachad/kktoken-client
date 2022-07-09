//
// Created by metagigachad on 09/07/22.
//

#pragma once

#include "User.h"
#include "TokensAmount.h"
#include "Signature.h"

class Transaction {
    // TODO: Getters, Encoders, Caching, Comparators
protected:
    User sender_;
    User recipient_;

    TokensAmount amount_;

    Signature signature_;   // Sender's digital signature

    // TODO: Is applied, Timestamp (May be CommittedTransaction wrapper instead)
};
