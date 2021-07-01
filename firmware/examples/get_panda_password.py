#!/usr/bin/env python3
import sys
from panda import Panda

def get_panda_password():

  try:
    print("Trying to connect to Panda over USB...")
    p = Panda()

  except AssertionError:
    print("USB connection failed")
    sys.exit(0)

  wifi = p.get_serial()
  print("SSID: " + wifi[0])
  print("Password: " + wifi[1])

if __name__ == "__main__":
  get_panda_password()
