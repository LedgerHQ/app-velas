#ifdef HAVE_BAGL

#include "ux.h"
#include "getPubkey.h"
#include "utils.h"
#include "sol/printer.h"

extern char publicKeyStr[BASE58_PUBKEY_LENGTH];

UX_STEP_NOCB(ux_display_public_flow_5_step, bnnn_paging,
             {
                 .title = "Pubkey",
                 .text = publicKeyStr,
             });
UX_STEP_VALID(ux_display_public_flow_6_step, pb,
              sendResponse(set_result_get_pubkey(), true),
              {
                  &C_icon_validate_14,
                  "Approve",
              });
UX_STEP_VALID(ux_display_public_flow_7_step, pb, sendResponse(0, false),
              {
                  &C_icon_crossmark,
                  "Reject",
              });

UX_FLOW(ux_display_public_flow, &ux_display_public_flow_5_step,
        &ux_display_public_flow_6_step, &ux_display_public_flow_7_step);

void get_pubkey_ui(void) {
    ux_flow_init(0, ux_display_public_flow, NULL);
}

#endif // HAVE_BAGL
