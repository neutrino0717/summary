syntax on
set tabstop=4       "how many spaces a tab should take up
set shiftwidth=4    "when using the >> or << commands, shift lines by 4 spaces
set expandtab       "converts all tabs to spaces!!!
set list listchars=tab:>-,trail:.,extends:>  "turn on invisibles.tabs into >-, and trailing spaces and blank lines 

set number
set cursorline      "show a visual line under the cursor's current line
set showmatch       "show the matching part of the pair for [] {} and ()

filetype plugin indent on
au FileType py set autoindent          "autoindent will indent the next line when you start a new line
au FileType py set smartindent         "smartindent will also indent after things like a colon (for if or for statements) and such
au FileType py set textwidth=79        " PEP-8 Friendly
let python_highlight_all = 1           " enable all Python syntax highlighting features
