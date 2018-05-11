import misaka as m
from pygments import highlight
from pygments.formatters import HtmlFormatter, ClassNotFound
from pygments.lexers import get_lexer_by_name
from pygments.styles import manni
import sys
import re

class HighlighterRenderer(m.HtmlRenderer):
    def blockcode(self, text, lang):
        try:
            lexer = get_lexer_by_name(lang, stripall=True)
        except ClassNotFound:
            lexer = None

        if lexer:
            formatter = HtmlFormatter(style='manni')
            return highlight(text, lexer, formatter)
        # default
        return '\n<pre><code>{}</code></pre>\n'.format(text.strip())

class MarkdownRenderer():
    def __init__(self):
        self.mdRenderer = m.Markdown(HighlighterRenderer(), extensions=('fenced-code','tables'))

    def manualReplace(self, s, r, t):
        l = len(s)
        for i in range(0,len(t)-l):
            if t[i:i+l] == s:
                t = t[0:i] + r + t[i+l:]
        return t

    def postRender(self, t, plus):
        t = re.sub('<table>','<table class="table" style="width: 50%;margin-left: 25%;">',t)
        return t
    def render(self, text, **kargs):
        if "plus" not in kargs:
            plus = False
        else:
            plus = kargs["plus"]
        pre = self.renderPlus(self.mdRenderer(text)) if plus else self.mdRenderer(text)
        return self.postRender(pre,plus)

    def subrender(self,r,t,temp):
        s = r.search(t)
        while s:
            rTemp= temp%s.groups()
            t = self.manualReplace(s.group(0),rTemp,t)
            s = r.search(t)
        return t

    def renderPlus(self, text):
        text = self.subrender(re.compile('<p>\![^\!](.*?)</p>'),text,"<div class='alert alert-dismissible alert-warning'>%s</div>")
        text = self.subrender(re.compile('<p>\!\!(.*?)</p>'),text,"<div class='alert alert-dismissible alert-danger'>%s</div>")
        # block quote magic
        c = re.compile('<blockquote>[\n\s]*<p>[\n\s]*(.*)!-(.*)[\n\s]*</p>[\n\s]*</blockquote>',flags=re.M)
        quote = "<blockquote class='blockquote' style='text-align: center'><p class='mb-0'>%s</p><footer class='blockquote-footer'><cite>%s</cite></footer></blockquote>"
        text = self.subrender(c,text,quote)
        return text


if __name__ == "__main__":
    header = '''
<head>
    <meta charset="utf-8">
    <title>Comp 2521 - Ass 2 FAQ</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <link rel="stylesheet" href="https://bootswatch.com/4/cosmo/bootstrap.min.css" media="screen">
    <style>
        h1 {text-align: center;}
        hr {margin-bottom: 5%};
    </style>   
    <style>
/* syntax highlighting css taken from  https://github.com/richleland/pygments-css/blob/master/manni.css */
.highlight {
  padding: 1em;
}
.highlight .hll { background-color: #ffffcc }
.highlight  { background: #f0f3f3; margin-top: 1em; margin-bottom: 1em}
.highlight .c { color: #0099FF; font-style: italic } /* Comment */
.highlight .err { color: #AA0000; background-color: #FFAAAA } /* Error */
.highlight .k { color: #006699; font-weight: bold } /* Keyword */
.highlight .o { color: #555555 } /* Operator */
.highlight .ch { color: #0099FF; font-style: italic } /* Comment.Hashbang */
.highlight .cm { color: #0099FF; font-style: italic } /* Comment.Multiline */
.highlight .cp { color: #009999 } /* Comment.Preproc */
.highlight .cpf { color: #0099FF; font-style: italic } /* Comment.PreprocFile */
.highlight .c1 { color: #0099FF; font-style: italic } /* Comment.Single */
.highlight .cs { color: #0099FF; font-weight: bold; font-style: italic } /* Comment.Special */
.highlight .gd { background-color: #FFCCCC; border: 1px solid #CC0000 } /* Generic.Deleted */
.highlight .ge { font-style: italic } /* Generic.Emph */
.highlight .gr { color: #FF0000 } /* Generic.Error */
.highlight .gh { color: #003300; font-weight: bold } /* Generic.Heading */
.highlight .gi { background-color: #CCFFCC; border: 1px solid #00CC00 } /* Generic.Inserted */
.highlight .go { color: #AAAAAA } /* Generic.Output */
.highlight .gp { color: #000099; font-weight: bold } /* Generic.Prompt */
.highlight .gs { font-weight: bold } /* Generic.Strong */
.highlight .gu { color: #003300; font-weight: bold } /* Generic.Subheading */
.highlight .gt { color: #99CC66 } /* Generic.Traceback */
.highlight .kc { color: #006699; font-weight: bold } /* Keyword.Constant */
.highlight .kd { color: #006699; font-weight: bold } /* Keyword.Declaration */
.highlight .kn { color: #006699; font-weight: bold } /* Keyword.Namespace */
.highlight .kp { color: #006699 } /* Keyword.Pseudo */
.highlight .kr { color: #006699; font-weight: bold } /* Keyword.Reserved */
.highlight .kt { color: #007788; font-weight: bold } /* Keyword.Type */
.highlight .m { color: #3BCEBF } /* Literal.Number */
.highlight .s { color: #CC3300 } /* Literal.String */
.highlight .na { color: #330099 } /* Name.Attribute */
.highlight .nb { color: #336666 } /* Name.Builtin */
.highlight .nc { color: #00AA88; font-weight: bold } /* Name.Class */
.highlight .no { color: #336600 } /* Name.Constant */
.highlight .nd { color: #9999FF } /* Name.Decorator */
.highlight .ni { color: #999999; font-weight: bold } /* Name.Entity */
.highlight .ne { color: #CC0000; font-weight: bold } /* Name.Exception */
.highlight .nf { color: #CC00FF } /* Name.Function */
.highlight .nl { color: #9999FF } /* Name.Label */
.highlight .nn { color: #00CCFF; font-weight: bold } /* Name.Namespace */
.highlight .nt { color: #330099; font-weight: bold } /* Name.Tag */
.highlight .nv { color: #003333 } /* Name.Variable */
.highlight .ow { color: #000000; font-weight: bold } /* Operator.Word */
.highlight .w { color: #bbbbbb } /* Text.Whitespace */
.highlight .mb { color: #3BCEBF } /* Literal.Number.Bin */
.highlight .mf { color: #3BCEBF } /* Literal.Number.Float */
.highlight .mh { color: #3BCEBF } /* Literal.Number.Hex */
.highlight .mi { color: #3BCEBF } /* Literal.Number.Integer */
.highlight .mo { color: #3BCEBF } /* Literal.Number.Oct */
.highlight .sa { color: #CC3300 } /* Literal.String.Affix */
.highlight .sb { color: #CC3300 } /* Literal.String.Backtick */
.highlight .sc { color: #CC3300 } /* Literal.String.Char */
.highlight .dl { color: #CC3300 } /* Literal.String.Delimiter */
.highlight .sd { color: #CC3300; font-style: italic } /* Literal.String.Doc */
.highlight .s2 { color: #CC3300 } /* Literal.String.Double */
.highlight .se { color: #CC3300; font-weight: bold } /* Literal.String.Escape */
.highlight .sh { color: #CC3300 } /* Literal.String.Heredoc */
.highlight .si { color: #AA0000 } /* Literal.String.Interpol */
.highlight .sx { color: #CC3300 } /* Literal.String.Other */
.highlight .sr { color: #33AAAA } /* Literal.String.Regex */
.highlight .s1 { color: #CC3300 } /* Literal.String.Single */
.highlight .ss { color: #FFCC33 } /* Literal.String.Symbol */
.highlight .bp { color: #336666 } /* Name.Builtin.Pseudo */
.highlight .fm { color: #CC00FF } /* Name.Function.Magic */
.highlight .vc { color: #003333 } /* Name.Variable.Class */
.highlight .vg { color: #003333 } /* Name.Variable.Global */
.highlight .vi { color: #003333 } /* Name.Variable.Instance */
.highlight .vm { color: #003333 } /* Name.Variable.Magic */
.highlight .il { color: #3BCEBF } /* Literal.Number.Integer.Long */
    </style>
</head><body style="margin: 5%"> <h1> Comp 2521 - Ass 2 FAQ </h1><hr> <div style="margin: 5%">
    '''
    footer = "</div></body>"
    mdRenderer = MarkdownRenderer()
    f = open(sys.argv[1])
    raw = f.read()
    f.close()
    r = mdRenderer.render(raw,plus=True)
    f = open(sys.argv[2],"w")
    f.write(header)
    f.write(r)
    f.write(footer)
    f.close()

