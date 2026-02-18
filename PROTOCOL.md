# Zener Project Protocols

## 1. Exit Code Awareness
- **Rule**: Every terminal command must be checked for success (Exit Code 0).
- **Action**: A failure is a **HALT**, not a retry trigger. Do not proceed until resolved.

## 2. Contextual Analysis
- **Rule**: If `arduino-cli` (or any tool) fails:
    1.  Read the error log.
    2.  Explain the cause in chat.
    3.  **WAIT** for user command ('Fix' or 'Proceed').

## 3. State Sync
- **Rule**: Ensure source files are saved and Local Git Commit is clean before attempting GitHub pushes.
- **Pre-Push Check**: Always run `git status` to ensure a clean working tree.

## 4. Wemos Specifics
- **Target**: Wemos D1 Mini Pro (ESP8266).
- **FQBN**: `esp8266:esp8266:d1_mini_pro`.
- **Warning**: A0 Pin Max Voltage = 3.2V. Always assume/verify voltage divider usage.
