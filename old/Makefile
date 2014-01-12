%.html: %.txt
	trans.pl $(TRANSOPTS) $(TRANSFLAGS) $(SW_OPTS) $<

%.ps: %.html
	html2ps $(HTML2PSFLAGS) -D -o $*.ps $<

%.pdf: %.ps
	ps2pdf $<  $*.pdf

# Use the appropriate template, attributes, and tags	
TRANSOPTS = -X Templates/template.html \
	-a cnix.att \
	-t cnix.tags

# All the files used in building pages
HELPER_FILES = Templates/template.html cnix.att cnix.tags 

# By default, build every Web page
all:	*.html 
	touch all

# Other dependences
*.html: *.att *.tags Templates/template.html
