# Oh My ZSH

---

## Установка

### Установка Oh My ZSH

```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

#### Должен быть установлен zsh и использоваться по умолчанию

### Установка темы powerlevel10k

```bash
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
```

#### Добавить в в .zshrc

```bash
ZSH_THEME="powerlevel10k/powerlevel10k"
```

#### Запуск модифицирования темы

```bash
p10k configure
```

---

## Плагины

### 1. **git**

- **Описание**: Добавляет множество сокращений и псевдонимов для команд `git`.
- **Примеры сокращений**:
  - `gst` → `git status`
  - `ga` → `git add`
  - `gcmsg` → `git commit -m`
- **Как включить**: Добавьте `git` в список плагинов в файле `.zshrc`.

### 2. **zsh-autosuggestions**

- **Описание**: Автоматически предлагает команды на основе истории команд.
- **Как установить**:

     ```bash
     git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
     ```

- **Как включить**: Добавьте `zsh-autosuggestions` в список плагинов в файле `.zshrc`.

### 3. **zsh-syntax-highlighting**

- **Описание**: Подсветка синтаксиса команд в терминале.
- **Как установить**:

     ```bash
     git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
     ```

- **Как включить**: Добавьте `zsh-syntax-highlighting` в список плагинов в файле `.zshrc`.

### 4. **autojump**

- **Описание**: Позволяет быстро перемещаться между директориями с помощью сокращений.
- **Как установить**:

     ```bash
     brew install autojump
     ```

- **Как включить**: Добавьте `autojump` в список плагинов в файле `.zshrc`.

### 5. **colored-man-pages**

- **Описание**: Добавляет цветовую подсветку для страниц руководства (`man`).
- **Как включить**: Добавьте `colored-man-pages` в список плагинов в файле `.zshrc`.

### 6. **docker**

- **Описание**: Добавляет сокращения и псевдонимы для команд `docker` и `docker-compose`.
- **Как включить**: Добавьте `docker` в список плагинов в файле `.zshrc`.

### 7. **extract**

- **Описание**: Универсальная команда для распаковки архивов различных форматов.
- **Пример использования**: `extract archive.zip`
- **Как включить**: Добавьте `extract` в список плагинов в файле `.zshrc`.

### 8. **history**

- **Описание**: Добавляет удобные команды для работы с историей команд.
- **Примеры команд**:
  - `h` → Показать историю команд.
  - `hsi` → Поиск по истории команд.
- **Как включить**: Добавьте `history` в список плагинов в файле `.zshrc`.

### 9. **sudo**

- **Описание**: Дважды нажатие клавиши `ESC` добавляет `sudo` к предыдущей команде.
- **Как включить**: Добавьте `sudo` в список плагинов в файле `.zshrc`.

### 10. **web-search**

- **Описание**: Добавляет команды для быстрого поиска в Google, Bing, Yahoo и других поисковых системах.
- **Примеры команд**:
  - `google search query`
  - `bing search query`
- **Как включить**: Добавьте `web-search` в список плагинов в файле `.zshrc`.

### 11. **vi-mode**

- **Описание**: Включает режим `vi` для редактирования команд в терминале.
- **Как включить**: Добавьте `vi-mode` в список плагинов в файле `.zshrc`.

### 12. **compleat**

- **Описание**: Улучшает автодополнение команд.
- **Как установить**:

     ```bash
     brew install compleat
     ```

- **Как включить**: Добавьте `compleat` в список плагинов в файле `.zshrc`.

### 13. **jsontools**

- **Описание**: Добавляет удобные команды для работы с JSON.
- **Примеры команд**:
  - `pp_json` → Красиво форматирует JSON.
  - `urlencode_json` → URL-кодирует JSON.
- **Как включить**: Добавьте `jsontools` в список плагинов в файле `.zshrc`.

### 14. **pip**

- **Описание**: Добавляет автодополнение для команд `pip`.
- **Как включить**: Добавьте `pip` в список плагинов в файле `.zshrc`.

### 15. **python**

- **Описание**: Добавляет удобные команды и псевдонимы для работы с Python.
- **Как включить**: Добавьте `python` в список плагинов в файле `.zshrc`.

### Как включить плагины

Чтобы включить плагины, откройте файл `.zshrc` в вашем любимом текстовом редакторе и найдите строку, которая выглядит примерно так:

```bash
plugins=(git)
```

Добавьте нужные плагины в этот список, разделяя их пробелами. Например:

```bash
plugins=(git zsh-autosuggestions zsh-syntax-highlighting autojump colored-man-pages docker extract history sudo web-search vi-mode compleat jsontools pip python)
```

После внесения изменений сохраните файл и перезапустите терминал или выполните команду:

```bash
source ~/.zshrc
```

---

```bash
plugins=(
   git zsh-autosuggestions
   zsh-syntax-highlighting
   colored-man-pages
   docker
   history
   udo
   extract
   web-search
   pip
   jsontools
   python
)
```
