<div align="center">

# 🔌 ESP8266 CTF — සිංහල

**ESP8266 NodeMCU වලින් ගොඩනගන ලද Beginner CTF**
Web security basics සිංහලෙන් ඉගෙන ගන්න 🇱🇰

![Platform](https://img.shields.io/badge/Platform-ESP8266%20NodeMCU-blue?style=flat-square&logo=arduino)
![Language](https://img.shields.io/badge/Language-සිංහල-orange?style=flat-square)
![Levels](https://img.shields.io/badge/Levels-3-green?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-purple?style=flat-square)
![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)

</div>

---

## 🎯 මෙය කුමක්ද?

මෙය **ESP8266 NodeMCU** board එකක් standalone Wi-Fi CTF server එකක් ලෙස භාවිතා කරන beginner-friendly **Capture The Flag** challenge එකකි. Router නැත, internet නැත — board එකම access point!

සිංහල භාෂාවෙන් ලියා ඇති **self-learning guide** සමඟ, real-world web security techniques **ව්‍යවහාරිකව** ඉගෙන ගන්න.

---

## 🏆 Levels

| Level | Challenge | Technique |
|-------|-----------|-----------|
| 🔍 **Level 1** | HTML Source Inspection | HTML comments තුළ flag |
| 🤖 **Level 2** | robots.txt Path Discovery | Hidden paths හඳුනා ගැනීම |
| 📡 **Level 3** | HTTP Header Credential Leak | Response headers analysis |

---

## 📦 ඔබට අවශ්‍ය දේ

- ESP8266 NodeMCU board × 1
- Micro USB cable (data-capable) × 1
- [Arduino IDE](https://www.arduino.cc/en/software) install කළ computer
- Power bank *(විකල්ප — portable use සඳහා)*

---

## 🚀 Quick Start

### 1. Arduino IDE Setup

**ESP8266 Board Manager URL** add කරන්න:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

`File → Preferences → Additional Boards Manager URLs`

```
Tools → Board → Boards Manager → "ESP8266" → Install
Tools → Board → NodeMCU 1.0 (ESP-12E Module)
```

### 2. Firmware Upload

```bash
# Repository clone කරන්න
git clone https://github.com/your-username/esp8266-ctf-sinhala.git

# firmware/ctf_firmware.ino Arduino IDE හි open කරන්න
# Tools → Port → නිවැරදි COM port තෝරන්න
# Upload ▶ button click කරන්න
```

### 3. CTF Start!

```
Wi-Fi:    HackMe_AP  (password නැත)
URL:      http://192.168.4.1
```

---

## 📡 Network Details

| Setting | Value |
|---------|-------|
| SSID | `HackMe_AP` |
| Password | *(open network)* |
| Server IP | `192.168.4.1` |
| Port | `80` (HTTP) |

---

## 📁 Repository Structure

```
esp8266-ctf-sinhala/
├── nodemcuCTF/
│   └── nodemcuCTF.ino       # Main Arduino sketch
├── ESP8266_CTF_Sinhala.docx  # Full Sinhala guide (Word)
└── README.md
```

---

## 📖 Firmware Overview

| Function | කාර්යය |
|----------|--------|
| `MAIN_PAGE` | Root `/` — Level 1 flag hidden in HTML comment |
| `LOGIN_PAGE` | `/login` GET — Base64 hint in HTML comment |
| `handleRoot()` | Main page + `X-Hint: admin:esp8266` header (Level 3 leak) |
| `handleRobots()` | `/robots.txt` — `/hidden-panel` disallowed |
| `handleHiddenPanel()` | Level 2 flag |
| `handleLogin()` | POST credentials → Level 3 flag or 401 |

---

## 🧠 ඔබ ඉගෙන ගන්නේ

- ✅ **HTML Source Inspection** — browser render නොකරන දේ කියවීම
- ✅ **Passive Reconnaissance** — `robots.txt` මගින් hidden paths සොයා ගැනීම
- ✅ **HTTP Header Analysis** — response metadata layer leak detect කිරීම
- ✅ **Browser DevTools** — Network tab, response headers
- ✅ **HTTP fundamentals** — GET, POST, status codes, request/response cycle

---

## 🚨 Flags

> ⚠️ **Spoiler alert!** — challenges solve කිරීමට පෙර බලන්න එපා 😄

<details>
<summary>🚩 Flags reveal කරන්න</summary>

| Level | Flag |
|-------|------|
| Level 1 | `FLAG{inspect_the_source}` |
| Level 2 | `FLAG{robots_reveal_paths}` |
| Level 3 | `FLAG{headers_leak_information}` |

</details>

---

## 🛠️ Troubleshooting

| ⚠️ ගැටලුව | ✅ විසඳුම |
|------------|-----------|
| HackMe_AP නොපෙනේ | ESP8266 restart, 10s රැඳෙන්න |
| Upload fail | COM port හා USB cable (data) check කරන්න |
| 192.168.4.1 unreachable | HackMe_AP connected ද? |
| X-Hint නොපෙනේ | DevTools → Network → **Response** Headers |
| Serial garbage | Baud rate → **115200** |

---

## 💡 Extra Challenges (Ideas)

- [ ] 💡 **LED Blink** — correct flag submit කළ විට GPIO2 LED blink
- [ ] 📺 **OLED Scoreboard** — live flag count display
- [ ] 🍪 **Level 4: Cookie Manipulation** — `role=player` → `role=admin`
- [ ] 🎭 **Fake Firmware Update** — phishing trap `/update`
- [ ] 📁 **SPIFFS Storage** — HTML pages file system වෙත move කිරීම

---

## 📚 ඊළඟට ඉගෙන ගන්න

- [OWASP Top 10](https://owasp.org/www-project-top-ten/) — Most critical web vulnerabilities
- [TryHackMe](https://tryhackme.com) — Beginner-friendly legal hacking labs
- [HackTheBox](https://www.hackthebox.com) — Structured pentesting practice

---

## ⚠️ Disclaimer

මෙම project එක **educational purposes** සඳහා පමණි. ඔබේ permission නොමැති systems, networks, හෝ devices වලට මෙම techniques භාවිතා නොකරන්න. Always hack **legally** and **ethically**.

---

## 📄 License

MIT License — free to use, modify, and share with attribution.

---

<div align="center">

Made with ❤️ for the Sri Lankan cybersecurity community 🇱🇰

**Happy Hacking!** 🔐

</div>
