

#ifndef SRC_SRC_STRUCTS_STRUCTURES_H_
#define SRC_SRC_STRUCTS_STRUCTURES_H_

#include <cstdint>
#include <vector>

// todo: make structures Serializable (serialization/Serializable)

typedef unsigned char uchar;
typedef uchar* string;

/// Using Pay-to-Pubkey (P2PK) for transaction verification

/** @brief Outpoint contains information about transaction source
 *  @param hash source hash
 *  @param index source output index
 */
struct Outpoint
{
    string hash;
    uint16_t index;
};

/** @brief TxInput contains information about transaction input
 *  @param previous_output input hash
 */
struct TxInput
{
    Outpoint previous_output;
    string signature; // using Pay-to-Pubkey (P2PK) for transaction verification
};

/** @brief TxOutput contains information about transaction output
 *  @param count number of cash to spend
 */
struct TxOutput
{
    uint64_t count;
    string publickey; // using Pay-to-Pubkey (P2PK) for transaction verification
};

/** @brief Transaction contains information about transaction in blockchain
 *  @param icount count of inputs
 *  @param ocount count of outputs
 *  @param inputs transaction inputs
 *  @param outputs transaction outputs
 */
struct Transaction
{
    uint32_t icount;
    std::vector<TxInput> inputs; // todo: link with icount

    uint32_t ocount;
    std::vector<TxOutput> outputs; // todo: link with ocount
};

/** @brief Block contains information about block in blockchain
 *  @param prev hash of previous block
 *  @param merkle_root merkle tree root hash
 *  @param timestamp timestamp when miner started hashing the header
 *  @param nbits target threshold
 *  @param nonce number to get hash less or equals to the target threshold
 *  @param tcount count of transactions
 *  @param transactions block transactions
 */
struct Block
{
    struct
    {
        string prev;
        string merkle_root;
        uint32_t timestamp;

        uint32_t nbits;
        uint32_t nonce;
    }
    header;

    uint32_t tcount;
    std::vector<Transaction> transactions;
};

typedef std::vector<Block> Chain;


#endif//SRC_SRC_STRUCTS_STRUCTURES_H_
