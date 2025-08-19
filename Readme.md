# WCleaner

# 👋 About

**WCleaner** is a **lightweight** utility written in ***C*** using **standard libraries**. It cleans up ***cache*** and
***junk*** folders, displays ***logs*** in real-time, and saves them to a ***.txt*** file

# 🌟 Features:

- 🗑️ Clears temporary files & cache

- 📝 Logs all actions (on-screen + saved to log.txt)

- 🚀 Lightweight & fast (no dependencies, pure C)

- ⚙️ Configurable paths (customize folders to clean)

# 📥 Install

- Option 1
    1. Download release
    2. Add WCleaner.exe file to path

- Option 2
    1. Clone repository
    ``` bash
    git clone https://github.com/Nokskiy/WCleaner.git
    ```
    2. Build project
    ``` bash
       mkdir build | gcc ./src/main.c -o ./build/WCleaner.exe
    ```
    3. Add WCleaner.exe file to path

# 🚀 Usage

```bash
  WCleaner
```

> [!IMPORTANT]
> ***When using from the environment path, the logs will be created in the user folder***

# 🤝 Contibuting

***Contributions are welcome***

You can:

- Improve the code

- Add directories for cleaning

- Add new features