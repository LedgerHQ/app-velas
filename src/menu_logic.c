#include "menu.h"
#include "os.h"

void display_settings(void);
void switch_allow_blind_sign_data(void);
void switch_pubkey_display_data(void);

void exit_app(void) {
  os_sched_exit(-1);
}

//////////////////////////////////////////////////////////////////////////////////////
// Allow blind signing submenu

void allow_blind_sign_data_change(enum BlindSign blind_sign) {
  uint8_t value;
  switch (blind_sign) {
  case BlindSignDisabled:
  case BlindSignEnabled:
    value = (uint8_t)blind_sign;
    nvm_write((void *)&N_storage.settings.allow_blind_sign, &value,
              sizeof(value));
    break;
  }
  ui_idle();
}
