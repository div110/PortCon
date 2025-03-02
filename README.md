# Portcon

Portcon is a slim and efficient command-line tool designed for managing Gentoo's `make.conf` file. It simplifies the process of managing USE flags, Licenses, and configuring other Portage options.

---

## ✨ Features
 🔹 Easily manage USE flags
 
 🔹 Optimize compilation through `MAKEOPTS`

 🔹 Configure various Portage options
 
 🔹 Lightweight and blazing fast, written in C
 

---

## 📦 Installation

### Prerequisites
Ensure you have the necessary build tools installed:
```sh
sudo emerge --ask sys-devel/gcc make
```

### Build & Install
Clone the repository and compile Portcon:
```sh
git clone https://github.com/div110/portcon
cd portcon
make
```

---

## ⚙ Configuration
Portcon modifies `/etc/portage/make.conf` directly. It is recommended to back up this file before making changes.

---

## 🗑 Uninstallation
To remove Portcon:
```sh
make clean
```

---

## 🤝 Contributing
We welcome contributions! Feel free to submit pull requests, bug reports, and feature requests via GitHub.

---

## 📜 License
This project is licensed under the BSD-3-Clause license.

---

## 👤 Author
Created by **div110**

