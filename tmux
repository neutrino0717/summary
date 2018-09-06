# Shift arrow to switch windows
# bind -n means without c-b, S is Alt
bind -n S-Left  previous-window
bind -n S-Right next-window

# Use Alt-arrow keys without prefix key to switch panes
# bind -n means without c-b, M is Alt
bind -n M-Left  select-pane -L
bind -n M-Right select-pane -R
bind -n M-Up    select-pane -U
bind -n M-Down  select-pane -D
bind -n M-j     resize-pane -D
bind -n M-k     resize-pane -U
bind -n M-h     resize-pane -L
bind -n M-l     resize-pane -R

# Reload tmux config
# bind seems thj same as bind-key
bind r source-file ~/.tmux.conf

# Automatically set window title
set-window-option -g automatic-rename on
set-option -g set-titles on

#bind-key means c-b
bind-key h split-window -h
bind-key v split-window -v

# THEME
set -g status-bg black
set -g status-fg white
set -g window-status-current-bg white
set -g window-status-current-fg black
set -g window-status-current-attr bold
set -g status-interval 60
set -g status-left-length 30
set -g status-left '#[fg=green](#S) #(whoami)'
set -g status-right '#[fg=yellow]#(cut -d " " -f 1-3 /proc/loadavg)#[default] #[fg=white]%H:%M#[default]'

set -g base-index 1
set -g default-terminal screen-256color
set -g status-keys vi
set -g history-limit 10000

#setw means set-window-option
setw -g mode-keys vi
setw -g mode-mouse on
setw -g monitor-activity on
