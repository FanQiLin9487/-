# 快問快答 - C++ 限時答題小遊戲 🎮

## 📌 專案介紹
這是一款使用 **C++ 物件導向程式設計 (OOP)** 開發的限時答題小遊戲，題目會依序出現，玩家必須在限定時間內作答，系統會自動判分與顯示結果等級。

---

## 🧱 系統架構
- 題庫系統：內建題目與選項
- 計分系統：每題 10 分，依答對題數統計
- 時間控制：每題限時 15 秒，未作答視為逾時
- 模組化設計：使用多個 `.cpp` 與 `.h` 檔案組成

---

## 🖥️ 執行環境
- 適用平台：**Windows**
- 編譯器：**Code::Blocks**, 或其他支援 C++11 的 IDE（如 Dev-C++, Visual Studio, g++）

---

## 📁 檔案結構

CloudJudge/
├── main.cpp // 主程式
├── GameManager.h / .cpp // 遊戲邏輯模組
├── Question.h / .cpp // 題目資料模組
├── README.md // 使用說明文件

---

## ▶️ 執行方式（以 Code::Blocks 為例）

1. 開啟 Code::Blocks，選擇 `File > New > Project > Console Application`。

2. 選擇 C++，按「Next」，設定專案名稱與儲存位置。

3. 在左側 Project 樹中右鍵點選 `Sources` > `Add files` → 加入 `main.cpp`、`GameManager.cpp`、`Question.cpp`。

4. 同理加入 `Headers` → `GameManager.h`、`Question.h`。

5. 點選「Build and Run（F9）」開始執行。

---

## 📸 遊戲流程

1. 顯示題目與選項

2. 倒數 15 秒（可提前輸入答案）

3. 顯示答對或答錯

4. 顯示下一題，直到結束

5. 統計分數與等級

---

## 🧑‍💻 額外設定（可選）

- 若要擴充題庫，可在 `GameManager.cpp` 中修改 `questions` 初始化區段。

- 可新增功能如「排行榜」、「記錄玩家名稱」、「讀檔出題」等。

---

專案製作：

- 李威德

- 吳浚愷

- 郭宬愷

第五組 | 資工1B  