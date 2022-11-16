# DataBase
<img src="https://img.shields.io/github/license/DimaPermyakov/Cbeer?color=brightgreen" alt="MIT License"> <img src="https://img.shields.io/badge/language-С++-purple.svg" alt="С++ Language">

Программа просит ввести данные по студентам. Каждый новый студент - новая структурная переменная,
которая позже заносится в map&lt;size_t, Student&gt;<br><dd>
где: 
* size_t - Номер студента
* Student - Струтура состоит из имени, возраста и достижений, где 
  - map&lt;string, mark&gt; - достижения, 
  - string - наз.предмета, 
  - mark - константная переменная из enum</dd>
