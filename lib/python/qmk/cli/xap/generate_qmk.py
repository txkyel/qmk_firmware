"""This script generates the XAP protocol generated source to be compiled into QMK.
"""
from milc import cli

from qmk.path import normpath
from qmk.xap.gen_firmware.generator import generate_inline, generate_header


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.subcommand('Generates the XAP protocol include.')
def xap_generate_qmk_inc(cli):
    """Generates the XAP protocol inline codegen file, generated during normal build.
    """
    generate_inline(cli.args.output)


@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.subcommand('Generates the XAP protocol include.')
def xap_generate_qmk_h(cli):
    """Generates the XAP protocol header file, generated during normal build.
    """
    generate_header(cli.args.output)
