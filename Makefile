TARGET_DIR := target
LECTURE_SOURCES := $(wildcard lectures/*/main.tex)
LECTURES := $(patsubst lectures/%/main.tex,%,$(LECTURE_SOURCES))

# Flags for latexmk
LATEX_FLAGS := -pdf -interaction=nonstopmode -lualatex

.PHONY: all clean dev list $(LECTURES)
.ONESHELL:

# Default: Build all lectures
all: $(LECTURES)

# Dynamic target for each lecture
# Usage: make abc
$(LECTURES):
	@echo "--- Building: $@ ---"
	@mkdir -p $(TARGET_DIR)/$@
	TEXINPUTS="lectures/$@/:" BIBINPUTS="lectures/$@/:" latexmk $(LATEX_FLAGS) -view=none -outdir=$(TARGET_DIR)/$@ -jobname="$@" lectures/$@/main.tex

# Dev mode: Watch a specific lecture
# Usage: make dev LEC=abc
dev:
	@LEC=$$(echo "$(LECTURES)" | tr ' ' '\n' | fzf --prompt="Select lecture to watch: ")
	@mkdir -p $(TARGET_DIR)/$(LEC)
	TEXINPUTS="lectures/$$LEC/:" latexmk $(LATEX_FLAGS) -pvc -outdir=$(TARGET_DIR)/$$LEC lectures/$$LEC/main.tex

# Helper to see what was detected
list:
	@echo "Detected lectures:"
	@for lec in $(LECTURES); do echo "  - $$lec"; done

# Wipe the target directory
clean:
	rm -rf $(TARGET_DIR)
