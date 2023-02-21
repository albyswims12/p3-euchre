// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include "Pack.h"
#include <array>
#include <vector>
#include "Card.h"

using namespace std;

  // EFFECTS: Initializes the Pack to be in the following standard order:
  //          the cards of the lowest suit arranged from lowest rank to
  //          highest rank, followed by the cards of the next lowest suit
  //          in order from lowest to highest rank, and so on.
  // NOTE: The standard order is the same as that in pack.in.
  // NOTE: Do NOT use pack.in in your implementation of this function
  Pack::Pack(){
    int counter = 0;
    for(int i = SPADES; i <= DIAMONDS; ++i){//traverse through suits
        for(int j = NINE; j <= ACE; ++j){//traverse through ranks
          Suit tempsuit = static_cast<Suit>(i);
          Rank temprank = static_cast<Rank>(j);
            Card tempcard = Card(temprank,tempsuit);
            cards[counter] = tempcard;
            counter++;
        }
    }
    next = 0;//initialize next
  }

  // REQUIRES: pack_input contains a representation of a Pack in the
  //           format required by the project specification
  // MODIFIES: pack_input
  // EFFECTS: Initializes Pack by reading from pack_input.
  Pack::Pack(std::istream& pack_input){
    Rank rank;
    string random;
    Suit suit;
    int counter = 0;
    while (pack_input >> rank >> random >> suit){
      Card tempcard = Card(rank,suit);
      cards[counter] = tempcard;
      counter++;
    }
    next = 0;
  }

  // REQUIRES: cards remain in the Pack
  // EFFECTS: Returns the next card in the pack and increments the next index
  Card Pack::deal_one(){
    next++;//increment before return
    return cards[next-1];
  }

  // EFFECTS: Resets next index to first card in the Pack
  void Pack::reset(){
    next = 0;
  }

  // EFFECTS: Shuffles the Pack and resets the next index. This
  //          performs an in shuffle seven times. See
  //          https://en.wikipedia.org/wiki/In_shuffle.
  void Pack::shuffle(){
    vector<Card> tempcards;
    Card random = Card();
    for(int i = 0; i < 7; i++){
      int counter = 0;
      for (int k = 0; k < PACK_SIZE/2; k++){
        tempcards.push_back(random);
        tempcards.push_back(cards[counter]);
        counter++;
      }
      for (int j = 0; j < PACK_SIZE; j+=2){
        tempcards[j] = cards[counter];
        counter++;
      }
      for(int i = 0; i < PACK_SIZE; ++i){//copy temp into original
        cards[i] = tempcards[i];
      }
      tempcards.clear();
    }
  }

  // EFFECTS: returns true if there are no more cards left in the pack
  bool Pack::empty() const{
    if(next > 23){
      return true;
    }
    return false;
  }
