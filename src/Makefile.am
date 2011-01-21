ANTLR=antlr3

grammar_files= \
						$(srcdir)/belle_sip_uri.g \
						$(srcdir)/belle_sip_message.g

generated_src= \
	belle_sip_uriParser.c belle_sip_uriParser.h \
	belle_sip_uriLexer.c belle_sip_uriLexer.h \
	belle_sip_messageParser.c belle_sip_messageParser.h \
	belle_sip_messageLexer.c belle_sip_messageLexer.h

$(builddir)/generated_src_stamp : $(grammar_files)
	$(ANTLR) -make -fo $(builddir) $(grammar_files)
	touch $(builddir)/generated_src_stamp

$(generated_src)	:	$(builddir)/generated_src_stamp
	

BUILT_SOURCES=$(generated_src)

noinst_LTLIBRARIES=libbellesip_generated.la

nodist_libbellesip_generated_la_SOURCES=$(generated_src)

libbellesip_generated_la_CFLAGS=$(LESS_STRICT_OPTIONS)

lib_LTLIBRARIES=libbellesip.la


libbellesip_la_SOURCES=clock_gettime.h \
									belle_sip_uri_impl.c \
									belle_sip_headers_impl.c \
									belle_sip_utils.c belle_sip_internal.h \
									belle_sip_object.c \
									belle_sip_loop.c \
									belle_sip_resolver.c belle_sip_resolver.h \
									belle_sip_parameters.c \
									transaction.c \
									listeningpoint.c \
									sipstack.c \
									provider.c \
									sender_task.c sender_task.h \
									message.c

libbellesip_la_CFLAGS=$(STRICT_OPTIONS)

libbellesip_la_LIBADD=libbellesip_generated.la -lantlr3c

INCLUDES=-I$(top_srcdir)/include

EXTRA_DIST=$(grammar_files)

CLEANFILES=$(generated_src) *.tokens generated_src_stamp