#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <memory>
#include <stack>

#include "State.h"

namespace Game {
typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
  StateMachine(){};
  ~StateMachine(){};

  void AddState(StateRef new_state, bool is_replacing = true);
  void RemoveState();

  void ProcessStateChanges();

  StateRef &GetActiveState();

private:
  std::stack<StateRef> States_;
  StateRef New_State_;

  bool Is_Adding_;
  bool Is_Removing_;
  bool Is_Replacing_;
};
} // namespace Game

#endif // STATE_MACHINE_H
