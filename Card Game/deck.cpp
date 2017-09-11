 
#ifndef StdCardDeckH
#define StdCardDeckH
 
#include <string>
#include <sstream>
#include <algorithm>
 
const char HEART   = 0x03;   // May Not Work on
const char DIAMOND = 0x04;   // certain systems
const char CLUB    = 0x05;   // These are DOS standard
const char SPADE   = 0x06;   // ASCII characters
 
struct Card {
    char Suit;
    int trueVal;
    std::string faceVal;
    std::string fullName;
};
 
class Deck
{
  public:
    Deck(int DeckSize);
   ~Deck(void);
 
    void Shuffle(int passes);
    Card Deal(void);
    void Collect(void);
 
  private:
    Card *CardDeck;
    int CurrCard;
    const int DECK_SIZ;
};
 
Deck::Deck(int DeckSize = 1) : DECK_SIZ( DeckSize ) {
  std::ostringstream sConv;
  int CurrSuit, CurrDeck;
 
  CardDeck = new Card[52 * DECK_SIZ];
  for (CurrDeck = 0; CurrDeck < DECK_SIZ; CurrDeck++) {
    for (CurrSuit = 0; CurrSuit < 4; CurrSuit++) {
      for (CurrCard = 0; CurrCard < 13; CurrCard ++) {
        if ((CurrCard + 1) % 13 == 1) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].faceVal = 'A';
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName = "Ace of ";
           }
        else if ((CurrCard + 1) % 13 == 11) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].faceVal = 'J';
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName = "Jack of ";
           }
        else if ((CurrCard + 1) % 13 == 12) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].faceVal = 'Q';
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName = "Queen of ";
           }
        else if ((CurrCard + 1) % 13 == 0) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].faceVal = 'K';
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName = "King of ";
           }
        else {
           sConv << (CurrCard + 1) % 13;
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].faceVal = sConv.str();
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName = sConv.str() + " of ";
           sConv.str("");
        }
        if (CurrSuit == 0) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].Suit = HEART;
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName += "Hearts";
           }
        else if (CurrSuit == 1) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].Suit = DIAMOND;
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName += "Diamonds";
           }
        else if (CurrSuit == 2) {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].Suit = CLUB;
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName += "Clubs";
           }
        else {
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].Suit = SPADE;
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].fullName += "Spades";
           }
        if ((CurrCard + 1) % 13 < 10)
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].trueVal = (CurrCard + 1) % 13;
        else
           CardDeck[CurrCard + (CurrSuit * 13) + (CurrDeck * 52)].trueVal =  10;
      }
    }
  }
  CurrCard = 0;
}
 
Deck::~Deck(void) {
  delete[] CardDeck;
}
 
void Deck::Shuffle(int passes = 1) {
  int currShuffle;
  for (currShuffle = 0; currShuffle < passes; currShuffle++)
      std::random_shuffle(CardDeck, CardDeck+DECK_SIZ*52);
}
 
Card Deck::Deal(void) {
  if ( CurrCard < DECK_SIZ * 52)
     return CardDeck[CurrCard++];
}
 
void Deck::Collect(void) {
   CurrCard = 0;
}
 
#endif /* StdCardDeckH */

