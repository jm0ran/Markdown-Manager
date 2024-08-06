### Project Summary

The goal of Markdown-Manager is to convert my knowledge base build out in markdown to JSON data that can be easily interpreted by whatever GUI I choose to pursue, likely web based (React or Angular who knows). The goal is to maintain my current documentation system using Obsidian while also rendering this content in some kind of GUI for browsing and display. 

As my workflow revolves around markdown in the context of obsidian I am looking to support are basic markdown syntax as well as some additions such as internal page to page links, file embedding (pdf for example), and obsidian's flavor of image rendering.

In terms of stretch goals one primary goal I have is to integrate some kind of system for managing flash cards and study sets.  I currently use Quizlet which works fine, but I'd like to create another solution that could read markdown files or some other format and display them on a web app for example.

In terms of implementation I'd like to use a mix of C and C++ to gain further experience in these languages. While there are plenty of libraries that I'm sure I could use I'd like to program a lot of the functionality at a lower level to gain a better understanding of the languages so another goal will be to avoid any large third party code libraries for conversion activity.

# Elements to Cover

**Paragraphs:**  Paragraphs are blocks of plain text separated by blank lines. Th
ese are the most simple forms of text and will be the default interpretation of lines

**Headers**: Headers are numbered 1-6 and are ordered in descending size, 1 being the largest 6 being the smallest. Headers are defined by 1-6 '#'  characters followed by a space. Headers must be at the start of a new line.

**Text Decoration**: Text decorations include bold, italic, strikethrough, and highlight. Bold is denoted by text surrounded by \*\* or \_\_.  Italics is surround by either \* \_. Strikethrough is surrounded by \~\~. Highlight is surrounded by \=\=. There are special conditions for italics nested in bold text, surround the bolded text with \*\* and surround the nested italic text with \_. For bold and italic the text can be surrounded in \*\*\* or \_\_\_. 


