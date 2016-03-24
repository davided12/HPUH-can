# **Arduino - CanBus mcp2515 - GET HPUH H4FSAE**

###A library that help you to create a data logger for the ECU GET HPUH H4FSAE

# **USAGE**

- Connect to a good power supply the ECU(9V 1.5A without sensors) on the pins: D1 for VCC and P4/Q4 for GND
- Jumper two pins CAN-H and CAN-L with a resistor of 120 ohm (it works also with 220 ohm)
- Connect two pins CAN-H and CAN-L from CAN_BUS_Shield to the ECU on the pins: D2 AND C2 respectively
- Take the complementary library from: https://github.com/Seeed-Studio/CAN_BUS_Shield
- Take the example from this repository and load it on the Arduino

# COMPONENTS
- Arduino Uno
- Can Bus shield for Arduino with MCP2515
- ECU GET HPUH H4FSAE (GK-HPUH-0002)


# License
HPUH-can library MIT license written by Davide Tarantino