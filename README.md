# Raccoon
PCB and firmware for a USB to CAN interface, with support for 4 CAN transceivers and an optional NEO-MP8 GNSS module. The design is a reverse-engineering of comma.ai's Black Panda. It uses a modified version of the [panda](https://github.com/commaai/panda) firmware/SDK.

![board](https://raw.githubusercontent.com/barbinbrad/raccoon/main/black-raccoon.png)

## Usage
For self-driving, it is better to buy a [black panda](https://comma.ai/shop/products/panda) from comma.ai. In addition to getting a more reliable product, you'll be supporting open-source software and a really smart group of people.

## Header
The design uses an automotive-grade Deutsch header, which eliminates the need for a switching relay. Feel free to replace this with something else. If you want to use ["ODB-C"](https://github.com/commaai/neo/blob/master/car_harness/OBD-C.sch.pdf) you'll need to use pins C0/C3 (inputs), C10/C11 (outputs). 

To use the deutsch header, you'll need a [crimper](https://www.buydeutsch.com/collections/crimpers/products/18890) and some parts:

- 1 [DTM13-12A](https://www.alliedelec.com/product/te-connectivity/dtm13-12pa/70979342/) or some variant of the header. This needs hand-soldered.
- 1 [DTM06-12S](https://www.buydeutsch.com/collections/dtm-series/products/dtm06-12sa), the male connector
- 1 [WM-12S](https://www.buydeutsch.com/collections/dtm-series/products/wm-12s), a wedgelock
- 12 [Crimpable Sockets](https://www.buydeutsch.com/products/0462-201-20141)

## Hand-Soldered Components
There are a few components that need purchased and hand-soldered to make the board work.
- 1 [USB-B Connector](https://www.digikey.com/en/products/detail/molex,-llc/0670688000/773801)
- 2 [Push Button Switches](https://www.mouser.com/ProductDetail/Grayhill/95C06C3RAT)

## GPS
If you order the board as-is from JLCPCB, you can use it with or without GPS. 

To use it with GPS, you'll need to hand-solder/install these parts:

- 1 [NEO-MP8-2](https://www.digikey.com/en/products/detail/u-blox/NEO-M8P-2/6150645)
- 1 [W2H15C4738AT1A](https://www.digikey.com/en/products/detail/avx-corporation/W2H15C4738AT1A/2004490), a feedthrough capacitor for the GPS antenna. 27uF
- 1 Active GNSS Antenna. See [Table 7](https://www.u-blox.com/sites/default/files/NEO-8Q-NEO-M8-FW3_HIM_UBX-15029985.pdf) in the NEO-M8P guide for recommendations. 

To use it without GPS, just jump the through-holes labeled NO_GPS. This will tell the firmware to ignore the GPS.

## Warning
The board design is untested because of the chip shortage. Use at your own risk.

## Credit
Credit to [mickabrig7](https://github.com/mickabrig7/raccoon) for the original design and his guidance.