#ifdef HAVE_NBGL

#include "nbgl_use_case.h"
#include "glyphs.h"
#include "menu.h"

enum {
    BLIND_SIGNING_TOKEN = FIRST_USER_TOKEN,
    SHORT_PUBKEY_TOKEN
};

#define SETTINGS_COUNT 2

static nbgl_layoutSwitch_t switches[SETTINGS_COUNT];

static const char* const infoTypes[] = {
    "Version"
};

static const char* const infoContents[] = {
    APPVERSION
};

static bool settings_nav(uint8_t page, nbgl_pageContent_t *content) {
    switch (page) {
        case 0:
            switches[0] = (nbgl_layoutSwitch_t) {
                .initState = N_storage.settings.allow_blind_sign ? ON_STATE : OFF_STATE,
                .text = "Allow bling signing",
                .subText = NULL,
                .token = BLIND_SIGNING_TOKEN,
                .tuneId = TUNE_TAP_CASUAL
            };
            switches[1] = (nbgl_layoutSwitch_t) {
                .initState = N_storage.settings.pubkey_display ? ON_STATE : OFF_STATE,
                .text = "Display short public keys",
                .subText = "Instead of long ones",
                .token = SHORT_PUBKEY_TOKEN,
                .tuneId = TUNE_TAP_CASUAL
            };
            content->type = SWITCHES_LIST;
            content->switchesList.nbSwitches = SETTINGS_COUNT;
            content->switchesList.switches = (nbgl_layoutSwitch_t*)switches;
            break;
        case 1:
            content->type = INFOS_LIST;
            content->infosList.nbInfos = 1;
            content->infosList.infoTypes = (const char**)infoTypes;
            content->infosList.infoContents = (const char**)infoContents;
            break;
    }
    return true;
}

static void settings_ctrl(int token, uint8_t index) {
    (void)index;
    uint8_t value;

    switch (token) {
        case BLIND_SIGNING_TOKEN:
            value = !N_storage.settings.allow_blind_sign;
            nvm_write((void*)&N_storage.settings.allow_blind_sign, (void*)&value, sizeof(value));
            break;
        case SHORT_PUBKEY_TOKEN:
            value = !N_storage.settings.pubkey_display;
            nvm_write((void*)&N_storage.settings.pubkey_display, (void*)&value, sizeof(value));
            break;
    }
}

void ui_settings(void) {
  nbgl_useCaseSettings(APPNAME" settings",
                       0,
                       2,
                       true,
                       ui_idle,
                       settings_nav,
                       settings_ctrl);
}

void ui_idle(void) {
  nbgl_useCaseHome(APPNAME,
                   &C_stax_velas_64px,
                   NULL,
                   true, // with settings button
                   ui_settings,
                   exit_app);
}

#endif // HAVE_NBGL
