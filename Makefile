TARGET_DIR := target
LECTURE_SOURCES := $(wildcard lectures/*/main.tex)
LECTURES := $(patsubst lectures/%/main.tex,%,$(LECTURE_SOURCES))

LATEX_FLAGS := -pdf -interaction=nonstopmode -lualatex

.PHONY: all clean dev list $(LECTURES)
.ONESHELL:

all: $(LECTURES)

$(LECTURES):
	@echo "--- Building: $@ ---"
	@mkdir -p $(TARGET_DIR)/$@
	TEXINPUTS="lectures/$@/:" BIBINPUTS="lectures/$@/:" latexmk $(LATEX_FLAGS) -view=none -outdir=$(TARGET_DIR)/$@ -jobname="$@" lectures/$@/main.tex

dev:
	@LEC=$$(echo "$(LECTURES)" | tr ' ' '\n' | fzf --prompt="Select lecture to watch: ")
	@mkdir -p $(TARGET_DIR)/$(LEC)
	TEXINPUTS="lectures/$$LEC/:" BIBINPUTS="lectures/$$LEC/:" latexmk $(LATEX_FLAGS) -pvc -outdir=$(TARGET_DIR)/$$LEC -jobname="$@" lectures/$$LEC/main.tex

list:
	@echo "Detected lectures:"
	@for lec in $(LECTURES); do echo "  - $$lec"; done

clean:
	rm -rf $(TARGET_DIR)
