#include <purescript.h>

void debug_trace(const purs_any_t * _x) {
	const purs_any_t * x = purs_any_unthunk(_x);
	const purs_any_tag_t * tag = purs_any_get_tag_maybe(x);
	if (tag == NULL) {
		printf("NULL\n");
	} else {
		/* TODO: expand on this */
		switch (*tag) {
			case PURS_ANY_TAG_BOGUS:
			    printf("<bogus>\n");
			    break;
			case PURS_ANY_TAG_INT:
			    printf("%i\n", *purs_any_get_int(x));
			    break;
			case PURS_ANY_TAG_NUMBER:
			    printf("%.2f\n", *purs_any_get_number(x));
			    break;
			case PURS_ANY_TAG_ABS:
			    printf("<function>\n");
			    break;
			case PURS_ANY_TAG_ABS_BLOCK:
			    printf("<block>\n");
			    break;
			case PURS_ANY_TAG_CONS:
			    printf("<cons>\n");
			    break;
			case PURS_ANY_TAG_RECORD:
			    printf("<record>\n");
			    break;
			case PURS_ANY_TAG_STRING:
			    printf("%s\n", purs_any_get_string(x)->data);
			    break;
			case PURS_ANY_TAG_CHAR:
			    printf("<char>\n");
			    break;
			case PURS_ANY_TAG_ARRAY:
			    printf("<array>\n");
			    break;
			case PURS_ANY_TAG_THUNK:
			    printf("<thunk>\n");
			    break;
			case PURS_ANY_TAG_FOREIGN:
			    printf("<foreign>\n");
			    break;
		}
	}
}

PURS_FFI_FUNC_3(Debug_Trace_trace, _, x, k, {
	debug_trace(x);
	return purs_any_app(k, NULL);
});

PURS_FFI_FUNC_3(Debug_Trace_spy, _, tag, x, {
	printf("%s:", purs_any_get_string(tag)->data);
	debug_trace(x);
	return x;
});
