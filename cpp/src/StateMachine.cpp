#include "StateMachine.h"

namespace Game {
void StateMachine::AddState(StateRef new_state, bool is_replacing) {
  this->Is_Adding_ = true;
  this->Is_Replacing_ = is_replacing;
  this->New_State_ = std::move(new_state);
}
void StateMachine::RemoveState() { this->Is_Removing_ = true; }

void StateMachine::ProcessStateChanges() {
  if (this->Is_Removing_ && !this->States_.empty()) {
    this->States_.pop();
    if (!this->States_.empty()) {
      this->States_.top()->Resume();
    }
    this->Is_Removing_ = false;
  }

  if (this->Is_Adding_) {
    if (!this->States_.empty()) {
      if (this->Is_Replacing_) {
        this->States_.pop();
      } else {
        this->States_.top()->Pause();
      }
    }
    this->States_.push(std::move(this->New_State_));
    this->States_.top()->Init();
    this->Is_Adding_ = false;
  }
}
} // namespace Game
