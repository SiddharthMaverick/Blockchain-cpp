#include <iostream>
#include <ctime>
#include <vector>

#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

int main(){
    // Start Blockchain
    Blockchain IITBCOIN;
    
    // Data for first block
    time_t data1Time;
    TransactionData data1(1.5, "Rishav", "Siddharth", time(&data1Time));
    IITBCOIN.addBlock(data1);
    
    // Data for second block
    time_t data2Time;
    TransactionData data2(0.2233, "Subhas", "Anuj", time(&data2Time));
    IITBCOIN.addBlock(data2);
    
    // Let's see what's in the IITBCOIN blockchain!
    IITBCOIN.printChain();
    
    // Is it valid?
    printf("\nIs chain still valid? %d\n", IITBCOIN.isChainValid());
    
    // Someone's getting sneaky
    Block *hackBlock = IITBCOIN.getLatestBlock();
    hackBlock->data.amount = 10000; 
    hackBlock->data.receiverKey = "Rishav"; 

    // Let's look at data
    IITBCOIN.printChain();

    // Awww! Why is it not valid?
    printf("\nIs chain still valid? %d\n", IITBCOIN.isChainValid());
    
    return 0;
}
