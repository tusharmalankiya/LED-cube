# 1-D 3x3 LED Cube Documentation
## Overview
The 1-D 3x3 LED Cube is a simple LED display consisting of a single row of LEDs arranged in a 3x3 grid. Each LED represents a pixel that can be individually controlled to display patterns, animations, or text. This project serves as an introduction to LED matrix displays and microcontroller programming using the ATmega32.

## Components
- LEDs (9 pieces)
- Current-limiting resistors (3 pieces)
- ATmega32 microcontroller
- Breadboard or PCB for circuit assembly
- Jumper wires
- Power supply (5V battery)

## Circuit Diagram
![simulation-gif][LED-cube - Proteus 8 Professional - Schematic Capture 2024-04-06 18-35-31](https://github.com/tusharmalankiya/LED-cube/assets/85736626/800b73a3-75c6-494b-8e03-48e2eaa2ac9e)

## Connection Scheme
### Layer Connections
- **Layer 1**: Connect the positive terminals of LEDs in the first layer in series. Connect the common wire of Layer 1 to a separate pin of the microcontroller.
- **Layer 2**: Repeat the same process for the second layer, connecting the positive terminals of LEDs in series and connecting the common wire of Layer 2 to another pin of the microcontroller.
- **Layer 3**: Repeat the process for the third layer, connecting the positive terminals of LEDs in series and connecting the common wire of Layer 3 to another pin of the microcontroller.

### Individual LED Connections
- For each layer, connect the negative terminals of the LEDs to separate pins of the microcontroller. Each pin corresponds to an individual LED within the layer.

### Microcontroller Pins
- Use separate pins of the microcontroller for each common wire of the layers. These pins will control the entire layer at once.
- Use separate pins of the microcontroller for each individual LED within each layer. These pins will control each LED individually.

### Microcontroller Configuration
- Configure the pins connected to the common wires of the layers as output pins.
- Configure the pins connected to the negative terminals of the LEDs as output pins.

> **Note**:
>
> Ensure proper current limiting and voltage requirements are met for the LEDs and microcontroller pins to avoid damage.

## Assembly Instructions
Follow these steps to assemble the 1-D 3x3 LED Cube:

1. **Prepare Components**: Gather all the necessary components listed above.
2. **Connection**: Follow the connection scheme described above to connect the LEDs and microcontroller pins accordingly.
3. **Wire Resistors**: Place current-limiting resistors in series with each layer to limit the current flowing through the LEDs.


## Programming
The source code for controlling the 1-D 3x3 LED Cube is available in the GitHub repository. The code is written in C and can be compiled using AVR-GCC or a compatible compiler. Follow these steps to program the microcontroller:

1. **Clone Repository**: Clone the repository to your local machine using git clone.
   ```bash
   git clone https://github.com/tusharmalankiya/LED-cube.git
   ```
2. **Open Project in IDE**: Open the project in an integrated development environment (IDE) such as Atmel Studio.
3. **Compile Code**: Compile the code using AVR-GCC or the compiler provided by your IDE.
4. **Load Firmware**: Upload the compiled code (`.hex` file from `LED-cube-atmel`>`Debug`) to the ATmega32 microcontroller using a programmer such as **extreamBurner** or an in-system programmer (ISP).

## Simulate with Proteus:

### Preparing the Simulation
1. **Download the Project**: Clone or download the project from GitHub to your local machine.

2. **Launch Proteus**: Launch Proteus Design Suite on your computer.

3. **Open Project**: from cloned github repository, open provided simulation from `simulation` directory.

4. **Upload Hex File**: In Proteus, right-click on the microcontroller and select "Edit Properties." Browse to the location of the hex file generated by the compiler and upload it to the microcontroller.

### Running the Simulation
1. **Start Simulation**: Once everything is configured, start the simulation by clicking the "Play" button in Proteus.

2. **Observe LED Behavior**: Observe the behavior of the LEDs in the simulation. They should respond according to the logic programmed in the project's code.


## Usage

Once the 1-D 3x3 LED Cube is assembled and programmed, it can be used to display various patterns, animations, or text. Experiment with different patterns by modifying the code or implementing custom animations. You can also integrate user input devices such as buttons or sensors to create interactive displays.

## License
This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code for both personal and commercial projects.
