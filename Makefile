# Makefile
#   Basic instructions for building the parts of this site.

# +------------------+------------------------------------------------
# | Standard targets |
# +------------------+

default: *.html

clean:
	rm -rf *.html

# +-----------------------+-------------------------------------------
# | Converting file types |
# +-----------------------+

%.ps: %.html
	html2ps -D -o $*.ps $<

%.pdf: %.ps
	ps2pdf $<  $*.pdf

%-md.html: %.md
	Markdown.pl $< > $@

%.html: %-md.html resources/template.html
	wrap-md-html $^ > $@


