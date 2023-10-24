#include <pair>
#include <priority_queue>
#include <vector>
class KokoBananas {
public:
  int lastHand(vector<int> hands, int K) {
    // add pair to prioirty queue
    // todo: add index as second decider for pq sorting
    for (int i = 0; i < hands.size(); i++) {
      pq.insert(make_pair(hands[i], i));
    }
    while (K > 0) {
      int hand = pq.top().first;
      int index = pq.top().second;
      pq.pop();
      int nextHand = pq.top().first;
      while (hand < nextHand && K > 0) {
        hand--;
        K--;
      }
      if (hand > 0) {
        pq.insert(make_pair(hand, index));
      }
    }
    return index;
  };