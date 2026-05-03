import random
import time

digitalPins = {
    pin: {
        "mode": None,
        "state": 0
    }
    for pin in range(13)
}

analogPins = {
    f"A{i}": {
        "mode": "input"
    }
    for i in range(6)
}

interrupts = {}
timerValue = 0


def mainCLI():
    global timerValue

    while True:
        command = input("> ").strip().lower().split()
        print("Output:", command)

        if len(command) == 0:
            continue

        elif command[0] == "exit":
            break

        elif command[0] == "user" or command[0] == "system":
            while True:
                enableCommand = input("> en ").strip().lower().split()

                if len(enableCommand) == 0:
                    continue

                if enableCommand[0] == "exit":
                    break

                elif enableCommand[0] == "show":

                    if len(enableCommand) < 2:
                        print("% Missing show target")

                    elif enableCommand[1] == "gpio":
                        for pin, info in digitalPins.items():
                            print(
                                f"Pin {pin} -> Mode: {info['mode']}, State: {'HIGH' if info['state'] else 'LOW'}"
                            )

                    elif enableCommand[1] == "system":
                        print("System Status: RUNNING")
                        print(f"Configured Interrupts: {interrupts}")

                    else:
                        print("% Invalid show command")

        elif command[0] == "configure":
            while True:
                configCommand = input("> config ").strip().lower().split()

                if len(configCommand) == 0:
                    continue

                if configCommand[0] == "exit":
                    break

                elif configCommand[0] == "gpio":

                    if len(configCommand) < 2:
                        print("% Missing GPIO subcommand")

                    elif configCommand[1] == "mode":

                        if len(configCommand) != 4:
                            print("% Usage: gpio mode <pin> <input/output>")

                        elif not configCommand[2].isdigit():
                            print("% Invalid pin number")

                        else:
                            pin = int(configCommand[2])

                            if pin not in digitalPins:
                                print("% Invalid digital pin")

                            elif configCommand[3] not in ["input", "output"]:
                                print("% Invalid mode")

                            else:
                                digitalPins[pin]["mode"] = configCommand[3]
                                print(f"Pin {pin} set to {configCommand[3].upper()}")

                    elif configCommand[1] == "write":

                        if len(configCommand) != 4:
                            print("% Usage: gpio write <pin> <high/low>")

                        elif not configCommand[2].isdigit():
                            print("% Invalid pin number")

                        else:
                            pin = int(configCommand[2])

                            if pin not in digitalPins:
                                print("% Invalid digital pin")

                            elif digitalPins[pin]["mode"] != "output":
                                print("% Pin not configured as output")

                            elif configCommand[3] not in ["high", "low"]:
                                print("% Invalid state")

                            else:
                                digitalPins[pin]["state"] = 1 if configCommand[3] == "high" else 0
                                print(f"Pin {pin} written {configCommand[3].upper()}")

                    elif configCommand[1] == "read":

                        if len(configCommand) != 3:
                            print("% Usage: gpio read <pin>")

                        elif not configCommand[2].isdigit():
                            print("% Invalid pin number")

                        else:
                            pin = int(configCommand[2])

                            if pin not in digitalPins:
                                print("% Invalid digital pin")

                            else:
                                state = "HIGH" if digitalPins[pin]["state"] else "LOW"
                                print(f"Pin {pin} = {state}")

                    else:
                        print("% Invalid GPIO command")

                elif configCommand[0] == "adc":

                    if len(configCommand) != 3 or configCommand[1] != "read":
                        print("% Usage: adc read <A0-A5>")

                    else:
                        channel = configCommand[2].upper()

                        if channel not in analogPins:
                            print("% Invalid ADC channel")

                        else:
                            value = random.randint(0, 1023)
                            print(f"{channel} = {value}")

                elif configCommand[0] == "timer":

                    if len(configCommand) < 2:
                        print("% Missing timer command")

                    elif configCommand[1] == "set":

                        if len(configCommand) != 3:
                            print("% Usage: timer set <ms>")

                        elif not configCommand[2].isdigit():
                            print("% Invalid timer value")

                        else:
                            timerValue = int(configCommand[2])
                            print(f"Timer set to {timerValue} ms")

                    elif configCommand[1] == "start":

                        print(f"Starting timer for {timerValue} ms...")
                        time.sleep(timerValue / 1000)
                        print("Timer Complete.")

                    else:
                        print("% Invalid timer command")

              
                elif configCommand[0] == "interrupt":

                    if len(configCommand) < 3:
                        print("% Invalid interrupt command")

                    elif configCommand[1] == "attach":
                        interrupts[configCommand[2]] = "attached"
                        print(f"Interrupt '{configCommand[2]}' attached")

                    elif configCommand[1] == "trigger":

                        if configCommand[2] not in interrupts:
                            print("% Interrupt not attached")

                        else:
                            print(f"[INTERRUPT] {configCommand[2]} triggered!")

                    else:
                        print("% Invalid interrupt command")

                else:
                    print("% Invalid config command")


mainCLI()