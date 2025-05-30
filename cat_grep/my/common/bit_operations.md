# Битовые операции

<a name="up"></a>

## Битовые маски

Каждый флаг представляет собой уникальный бит в целом числе. Нужно для комбинации флагов с помощью битовых операций. ([16-ричная система счисления](#16_the_number_system)).
Они представляют собой степени двойки в шестнадцатеричной системе счисления.
В двоичной системе это означает, что каждое значение имеет только один бит, установленный в 1, а остальные биты — в 0.

Уникальные биты могут храниться в одной переменной типа `int` с использованием битовых масок.
Битовые маски позволяют эффективно хранить и манипулировать наборами флагов или состояний в одной переменной.

- **`0x01`** (десятичное 1) — 0000 0000 0001
- **`0x02`** (десятичное 2) — 0000 0000 0010
- **`0x04`** (десятичное 4) — 0000 0000 0100
- **`0x08`** (десятичное 8) — 0000 0000 1000
- **`0x10`** (десятичное 16) — 0000 0001 0000
- **`0x20`** (десятичное 32) — 0000 0010 0000
- **`0x40`** (десятичное 64) — 0000 0100 0000
- **`0x80`** (десятичное 128) — 0000 1000 0000
- **`0x100`** (десятичное 256) — 0001 0000 0000

Каждый флаг занимает свой уникальный бит в переменной, что позволяет хранить несколько флагов в одной переменной типа int.

Несколько флагов могут храниться в одной переменной благодаря тому, что каждый флаг представлен уникальным битом. Побитовые операции позволяют устанавливать, сбрасывать и проверять отдельные биты в переменной.

---

## Основные понятия

1. **Бит**: Наименьшая единица информации в компьютере. Бит может иметь значение `0` или `1`.
2. **Битовая маска**: Это число, которое используется для манипулирования отдельными битами в другом числе.
3. **Побитовые операции**: Операции, которые работают с битами напрямую. Основные побитовые операции:
   - **И (`&`)**: Возвращает `1`, если оба бита равны `1`.
   - **ИЛИ (`|`)**: Возвращает `1`, если хотя бы один из битов равен `1`.
   - **ИСКЛЮЧАЮЩЕЕ ИЛИ (`^`)**: Возвращает `1`, если биты различны.
   - **НЕ (`~`)**: Инвертирует все биты числа.
   - **СДВИГ ВЛЕВО (`<<`)**: Сдвигает биты числа влево.
   - **СДВИГ ВПРАВО (`>>`)**: Сдвигает биты числа вправо.

---

## Работа с флагами

### Установка флага `(|=)`

Операция `|=` (битовое ИЛИ с присваиванием) используется для установки флага в переменной.

```C
int flags = 0;  // Изначально все флаги сброшены
flags |= FLAG_E;  // Установка флага FLAG_E
```

В двоичном виде:

```C
flags = 0000 0000
FLAG_E = 0000 0001
flags |= FLAG_E  ->  flags = 0000 0001
```

### Проверка флага `(&)`

Операция `&` (битовое И) используется для проверки, установлен ли определенный флаг.

```C
if (flags & FLAG_E) {
    // Флаг FLAG_E установлен
}
```

В двоичном виде:

```C
flags = 0000 0001
FLAG_E = 0000 0001
flags & FLAG_E  ->  0000 0001 (ненулевое значение, флаг установлен)
```

### Сброс флага `(&= ~)`

Операция `&= ~` (битовое И с инверсией) используется для сброса флага.

```C
flags &= ~FLAG_E;  // Сьрасывает флаг FLAG_E
```

В двоичном виде:

```C
flags = 0000 0001
~FLAG_E = 1111 1110
flags &= ~FLAG_E  ->  flags = 0000 0000
```

---

## Сноски

### 16-ричная система счисления

<a name="16_the_number_system"></a>

16-ричная система счисления (hexadecimal) очень удобна для работы с битами, потому что каждый разряд 16-ричного числа соответствует 4 битам (полубайту). Это делает ее очень удобной для представления битовых масок, так как:

- **Компактность**: 16-ричное представление короче, чем двоичное, что упрощает чтение и запись.
- **Прямое соответствие битов**: Каждый разряд 16-ричного числа соответствует 4 битам, что упрощает перевод между 16-ричной и двоичной системами.

Например, число 0x0F в двоичной системе будет 0000 1111, а число 0xF0 будет 1111 0000.

Запись битовых масок в виде `0x01`, `0x80`, `0x100` и т.д. использует 16-ричную систему счисления (hexadecimal).

- `0x10` — 16-ричное число, соответствующее десятичному 16.
- `0x2A` — 16-ричное число, соответствующее десятичному 42.
- `0xFF` — 16-ричное число, соответствующее десятичному 255.

#### Почему используется префикс 0x?

- **`Ясность и однозначность`**: Префикс 0x явно указывает, что число записано в 16-ричной системе счисления. Без этого префикса число 80 могло бы быть истолковано как десятичное число 80, что может привести к ошибкам.
- **`Соглашение`**: Использование префикса 0x стало стандартным соглашением в языках программирования, чтобы упростить чтение и написание кода. Это соглашение было заимствовано из языка программирования B, предшественника языка C.

- **Двоичная система**: Префикс 0b
- **Восьмеричная система**: Префикс 0

---

#### [doc.md](doc.md) [UP](#up)
