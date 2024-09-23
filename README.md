## [![Typing SVG](https://readme-typing-svg.demolab.com?font=Fira+Code&size=24&duration=3000&pause=1000&color=009BF7&vCenter=true&width=435&height=30&lines=%F0%9D%94%B9%F0%9D%95%84%E2%84%99+%F0%9D%95%A3%F0%9D%95%96%F0%9D%95%92%F0%9D%95%95%F0%9D%95%96%F0%9D%95%A3;%E2%84%9D%F0%9D%95%96%F0%9D%95%9D%F0%9D%95%96%F0%9D%95%92%F0%9D%95%A4%F0%9D%95%96)](https://git.io/typing-svg)
## Запуск из `Release`
1. Настроить `run.bat`, заменив название BMP файла из папки `images` на желаемый
```
@echo off
set PROJECT_DIR=%~dp0
set FILE_NAME=images/smile.bmp
start "" "%PROJECT_DIR%bmpreader.exe" "%PROJECT_DIR%%FILE_NAME%"
```
2. Запустить `run.bat`
## Запуск из `bmpreader.sln`
1. Настроить путь к желаемому файлу из папки `images`: перейти в `Проект` -> `Свойства` -> `Отладка` -> `Аргументы команды`
2. Заменить `$(ProjectDir)images\texture.bmp`
