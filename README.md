# 🎨 ملف README.md الاحترافي والمذهل

انسخ هذا المحتوى كاملاً وضعه في ملف `README.md` في جذر مشروعك:

```markdown
# 🏦 BankCore System

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual_Studio_2022-5C2D91?style=for-the-badge&logo=visual%20studio&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

**نظام مصرفي متكامل | Comprehensive Banking System**

_نظام إدارة مصرفية احترافي مبني بلغة C++ مع واجهات متعددة الخدمات_

</div>

---

## 📋 جدول المحتويات

<details>
<summary>اضغط لعرض المحتويات</summary>

- [نظرة عامة](#-نظرة-عامة)
- [المميزات الرئيسية](#-المميزات-الرئيسية)
- [المخطط المعماري](#-المخطط-المعماري)
- [هيكل المشروع](#-هيكل-المشروع)
- [التقنيات المستخدمة](#-التقنيات-المستخدمة)
- [المتطلبات](#-المتطلبات)
- [التثبيت والتشغيل](#-التثبيت-والتشغيل)
- [دليل الاستخدام](#-دليل-الاستخدام)
- [قاعدة البيانات](#-قاعدة-البيانات)
- [المساهم](#-المساهم)
- [الرخصة](#-الرخصة)

</details>

---

## 🌟 نظرة عامة

<div align="center">

```
╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║     BANKCORE SYSTEM  🏦                                 ║
║                                                           ║
║   ─────────────────────────────────────────────────┐     ║
║   │  نظام مصرفي متكامل لإدارة جميع العمليات البنكية │     ║
║   │  Comprehensive Banking Management System         │     ║
║   ─────────────────────────────────────────────────┘     
║                                                           ║
║    إدارة العملاء    💰 العمليات المالية                 ║
║   👤 إدارة المستخدمين  إدارة العملات                    ║
║    نظام المصادقة   📊 التقارير والأرصدة                ║
║                                                           ║
╚═══════════════════════════════════════════════════════════╝
```

</div>

**BankCore System** هو تطبيق سطح مكتب احترافي مبني بلغة **C++** يوفر حلاً متكاملاً لإدارة العمليات المصرفية. تم تصميم النظام باستخدام **نمط معماري قائم على الشاشات (Screen-Based Architecture)** حيث كل فئة (Class) تمثل واجهة مستخدم تقدم خدمة محددة للنظام المصرفي.

---

## ✨ المميزات الرئيسية

<div align="center">

| 🎯 الميزة | 📝 الوصف |
|-----------|----------|
| 👥 **إدارة العملاء** | إضافة، تعديل، حذف، بحث، وعرض قائمة العملاء |
| 👤 **إدارة المستخدمين** | نظام صلاحيات متكامل للمديرين والمستخدمين |
| 💰 **العمليات المالية** | إيداع، سحب، وتحويل الأموال بين الحسابات |
| 💱 **إدارة العملات** | أسعار الصرف والتحويل بين العملات المختلفة |
| 🔐 **نظام المصادقة** | تسجيل دخول آمن وتسجيل مستخدمين جدد |
| 📊 **الأرصدة** | عرض الأرصدة الكلية والتفاصيل المالية |
| 📜 **سجل المعاملات** | تتبع وتوثيق جميع العمليات المصرفية |
| 🎨 **واجهة مستخدم** | واجهة نصية احترافية وسهلة الاستخدام |

</div>

---

## ️ المخطط المعماري

<div align="center">

```
┌─────────────────────────────────────────────────────────────┐
│                    🏦 BANKCORE SYSTEM                        │
─────────────────────────────────────────────────────────────┘
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                    📱 MAIN SCREEN                            │
│              (clsMainScreen.h)                               │
└─────────────────────────────────────────────────────────────┘
                              │
        ┌─────────────────────┼─────────────────────┐
        ▼                     ▼                     ▼
┌───────────────┐   ┌──────────────────┐   ┌────────────────
│  🔐 LOGIN     │   │  👥 CLIENTS      │   │  💰 TRANSACTIONS│
│  SCREEN       │   │  MANAGEMENT      │   │  SCREEN        │
│               │   │                  │   │                │
│ clsLogin...   │   │ clsAddNew...     │   │ clsDeposit...  │
│ clsRegister.. │   │ clsDelete...     │   │ clsWithdraw... │
│               │   │ clsFind...       │   │ clsTransfer... │
│               │   │ clsUpdate...     │   │ clsTransferLog │
│               │   │ clsList...       │   │                │
└───────────────┘   └──────────────────┘   └────────────────┘
        │                     │                     │
        ▼                     ▼                     ▼
┌───────────────   ┌──────────────────┐   ┌────────────────┐
│  👤 USERS     │   │  💱 CURRENCIES   │   │  📊 REPORTS    │
│  MANAGEMENT   │   │  MANAGEMENT      │   │                │
│               │   │                  │   │ clsTotal...    │
│ clsManage...  │   │ clsCurrency...   │   │                │
│ clsFindUser.. │   │ clsCurrencyCalc..│   │                │
│ clsUpdate...  │   │ clsExchange...   │   │                │
└───────────────┘   ──────────────────┘   └────────────────
                              │
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                    🗄️ DATA LAYER                             │
│  ┌──────────┐  ┌──────────┐  ┌──────────────┐              │
│  │Clients   │  │Users     │  │Currencies    │              │
│  │.txt      │  │.txt      │  │.txt          │              │
│  └──────────┘  └──────────  └──────────────┘              │
│  ┌──────────────────────────────────────────┐              │
│  │TransferLog.txt                           │              │
│  └──────────────────────────────────────────┘              │
└─────────────────────────────────────────────────────────────┘
```

</div>

---

## 📁 هيكل المشروع

```
Project_Back/
│
├── 📂 x64/                          # مجلد البناء (64-bit)
│
├── 📄 Clients.txt                   #  بيانات العملاء
├── 📄 Users.txt                     # 💾 بيانات المستخدمين
├──  Currencies.txt                # 💾 بيانات العملات
── 📄 TransferLog.txt               #  سجل التحويلات
│
├── 🏗️ Core Classes
│   ├──  clsPerson.h               # 👤 الفئة الأساسية للشخص
│   ├── 📄 clsClient.h               # 👥 فئة العميل
│   ├── 📄 clsUser.h                 # 👤 فئة المستخدم
│   ├── 📄 clsCurrency.h             # 💱 فئة العملة
│   ├── 📄 clsDate.h                 # 📅 فئة التاريخ
│   ├── 📄 clsString.h               #  فئة النصوص
│   └──  clsUtil.h                 # 🛠️ أدوات مساعدة
│
├── 🖥️ Screen Classes (واجهات المستخدم)
│   ├── 📄 clsScreen.h               # 🎨 الفئة الأساسية للشاشات
│   ├── 📄 clsMainScreen.h           # 🏠 الشاشة الرئيسية
│   │
│   ├── 🔐 Authentication Screens
│   │   ├──  clsLoginRegisterScreen.h
│   │   └── 📄 clsLoginScreen.h
│   │
│   ├── 👥 Client Management Screens
│   │   ├── 📄 clsAddNewClientScreen.h
│   │   ├──  clsDeleteClientScreen.h
│   │   ├── 📄 clsFindClientScreen.h
│   │   ├── 📄 clsUpdateClientScreen.h
│   │   └── 📄 clsListClientsScreen.h
│   │
│   ├──  User Management Screens
│   │   ├──  clsAddNewUserScreen.h
│   │   ├── 📄 clsDeleteUserScreen.h
│   │   ├── 📄 clsFindUserScreen.h
│   │   ├── 📄 clsUpdateUserScreen.h
│   │   ├── 📄 clsListUsersScreen.h
│   │   └──  clsManageUsersScreen.h
│   │
│   ├── 💰 Transaction Screens
│   │   ├── 📄 clsDepositScreen.h
│   │   ├── 📄 clsWithdrawScreen.h
│   │   ├── 📄 clsTransferScreen.h
│   │   ├── 📄 clsTransferLogScreen.h
│   │   └──  clsTransactionsScreen.h
│   │
│   ├── 💱 Currency Screens
│   │   ├── 📄 clsCurrencyCalculatorScreen.h
│   │   ├── 📄 clsCurrencyExchangeMainScreen.h
│   │   └── 📄 clsUpdateCurrencyRateScreen.h
│   │
│   └── 📊 Reports Screens
│       └── 📄 clsTotalBalancesScreen.h
│
├── 🚀 Main Application
│   ├── 📄 Project_Back.cpp          # 🎯 نقطة البداية
│   └── 📄 Global.h                  # 🌐 الإعدادات العامة
│
└── ️ Project Files
    ├── 📄 Project_Back.sln          # حل Visual Studio
    ├── 📄 Project_Back.vcxproj      # مشروع Visual C++
    └──  Project_Back.vcxproj.filters
```

---

## 🛠️ التقنيات المستخدمة

<div align="center">

| التقنية | الاستخدام |
|---------|-----------|
| ![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=flat-square&logo=c%2B%2B&logoColor=white) | لغة البرمجة الأساسية |
| ![Visual Studio](https://img.shields.io/badge/Visual_Studio-2022-5C2D91?style=flat-square&logo=visual-studio&logoColor=white) | بيئة التطوير |
| ![Windows](https://img.shields.io/badge/Windows-API-0078D6?style=flat-square&logo=windows&logoColor=white) | واجهة برمجة التطبيقات |
| ![OOP](https://img.shields.io/badge/OOP-Design-276DC3?style=flat-square) | البرمجة كائنية التوجه |
| ![File I/O](https://img.shields.io/badge/File_IO-Storage-FF6B35?style=flat-square) | تخزين البيانات |

</div>

### المبادئ البرمجية المطبقة:
- ✅ **Object-Oriented Programming (OOP)**
- ✅ **Single Responsibility Principle**
- ✅ **Separation of Concerns**
- ✅ **Encapsulation**
- ✅ **Modular Architecture**

---

## 💻 المتطلبات

قبل البدء، تأكد من توفر التالي:

- [ ] **Windows 10/11** (64-bit)
- [ ] **Visual Studio 2022** مع workload "Desktop development with C++"
- [ ] **MSVC Compiler** (مضمن مع Visual Studio)
- [ ] **Git** (اختياري - للنسخ)

---

##  التثبيت والتشغيل

### الطريقة 1: من المصدر

```bash
# 1. استنساخ المستودع
git clone https://github.com/YOUR_USERNAME/BankCore-System.git

# 2. الانتقال لمجلد المشروع
cd BankCore-System

# 3. فتح المشروع في Visual Studio 2022
start Project_Back.sln

# 4. بناء المشروع (Build)
# في Visual Studio: Build > Build Solution (Ctrl+Shift+B)

# 5. تشغيل المشروع
# في Visual Studio: Debug > Start Without Debugging (Ctrl+F5)
```

### الطريقة 2: تحميل مباشر

1. اضغط على زر **Code** الأخضر أعلى الصفحة
2. اختر **Download ZIP**
3. استخرج الملفات
4. افتح `Project_Back.sln` في Visual Studio 2022

---

## 📖 دليل الاستخدام

### 🔐 تسجيل الدخول

```
────────────────────────────────────┐
│   🏦 BankCore System - Login       │
├────────────────────────────────────┤
│   Username: [________]             │
│   Password: [________]             │
│                                    │
│   [Login]  [Register New User]     │
└────────────────────────────────────┘
```

### 🏠 الشاشة الرئيسية

بعد تسجيل الدخول، ستظهر القائمة الرئيسية:

```
╔══════════════════════════════════════════════╗
║         🏦 BankCore Main Menu                ║
══════════════════════════════════════════════╣
║  [1]  Client Management                    ║
║  [2] 👤 User Management                      ║
║  [3] 💰 Transactions                         ║
║  [4] 💱 Currency Exchange                    ║
║  [5] 📊 Reports & Balances                   ║
║  [6]  Logout                               ║
╚══════════════════════════════════════════════╝
```

---

## 💾 قاعدة البيانات

يستخدم النظام **ملفات نصية** لتخزين البيانات:

| الملف | الوصف | التنسيق |
|-------|-------|---------|
| `Clients.txt` | بيانات العملاء | `Account#|PIN|Name|Phone|Email|Balance` |
| `Users.txt` | بيانات المستخدمين | `Username|Password|Permissions` |
| `Currencies.txt` | بيانات العملات | `Code|Name|Rate` |
| `TransferLog.txt` | سجل التحويلات | `Date|From|To|Amount|Balance` |

---

## 🤝 المساهمة

المساهمات مرحب بها! يرجى اتباع الخطوات التالية:

1. **Fork** المشروع
2. إنشاء فرع جديد (`git checkout -b feature/AmazingFeature`)
3. Commit التغييرات (`git commit -m 'Add some AmazingFeature'`)
4. Push للفرع (`git push origin feature/AmazingFeature`)
5. فتح **Pull Request**

---

##  الرخصة

هذا المشروع مرخص تحت رخصة **MIT** - انظر ملف [LICENSE](LICENSE) للتفاصيل.

---

## 👨‍ المطور

<div align="center">

**[اسمك هنا]**

📧 Email: your.email@example.com  
🐙 GitHub: [@YourUsername](https://github.com/Mulatef-Aldahia)  
💼 LinkedIn: [Your Profile](https://linkedin.com/in/yourprofile)

</div>

---

<div align="center">

## ⭐ إذا أعجبك المشروع، لا تنسَ إعطاءه نجمة!

```
    ⭐⭐⭐⭐⭐
    
    شكراً لزيارتك!
    Thanks for visiting!
```

**Made with ❤️ using C++**

</div>
```

---

## 📝 ملاحظات مهمة:

1. **استبدل** `Mulatef-Aldahia` باسم المستخدم الخاص بك على GitHub
2. **استبدل** `[ملاطف الداهية]` وبيانات الاتصال بمعلوماتك الحقيقية
3. **أضف** ملف `LICENSE` إذا أردت (يمكنك اختيار MIT License من GitHub مباشرة)
4. **يمكنك إضافة** لقطات شاشة حقيقية للمشروع في قسم "دليل الاستخدام"

---

## 🎨 للحصول على نتيجة أفضل:

### أضف لقطات شاشة:
أنشئ مجلد `screenshots/` وأضف صور للشاشات، ثم عدل README ليحتوي على:

```markdown
## 📸 لقطات الشاشة

<div align="center">

![Main Screen](screenshots/main-screen.png)
*الشاشة الرئيسية*

![Login Screen](screenshots/login-screen.png)
*شاشة تسجيل الدخول*

</div>
```

### أضف فيديو توضيحي:
```markdown
## 🎥 فيديو توضيحي

[![Watch the video](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID)
```