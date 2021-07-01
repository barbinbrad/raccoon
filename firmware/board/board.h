// ///////////////////////////////////////////////////////////// //
// Hardware abstraction layer for all different supported boards //
// ///////////////////////////////////////////////////////////// //
#include "board_declarations.h"
#include "boards/common.h"

// ///// Board definition and detection ///// //
#include "drivers/harness.h"
#include "boards/black.h"
#include "boards/white.h"

void detect_board_type(void) {
    // SPI lines floating: white (TODO: is this reliable? Not really, we have to enable ESP/GPS to be able to detect this on the UART)
    set_gpio_output(GPIOC, 14, 1);
    set_gpio_output(GPIOC, 5, 1);
    int has_gps  = !get_gpio_input(GPIOB, 15);
    if(has_gps == 0){
      hw_type = HW_TYPE_WHITE_PANDA;
      current_board = &board_white;
    }
    else{
      hw_type = HW_TYPE_BLACK_PANDA;
      current_board = &board_black;
    }  
}


// ///// Configuration detection ///// //
bool has_external_debug_serial = 0;

void detect_configuration(void) {
  // detect if external serial debugging is present
  has_external_debug_serial = detect_with_pull(GPIOA, 3, PULL_DOWN);
}

// ///// Board functions ///// //
// TODO: Make these config options in the board struct
bool board_has_gps(void) {
  return (hw_type == HW_TYPE_BLACK_PANDA);
}

bool board_has_gmlan(void) {
  return false;
}

bool board_has_obd(void) {
  return true;
}

bool board_has_lin(void) {
  return false;
}

bool board_has_rtc(void) {
  return false;
}

bool board_has_relay(void) {
  return false;
}
