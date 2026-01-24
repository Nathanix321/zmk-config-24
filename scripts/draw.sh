#!/usr/bin/env bash

# Navigate to draw directory
cd draw

# Create temporary directory
mkdir temp

# Separate target files
cp keymap.yaml temp/keymap.yaml
cp keymap.yaml temp/keymap-noseperatecombos.yaml
cp keymap.yaml temp/keymap-onlyseperatecombos.yaml

yq -i 'del(.combos[] | select(.draw_separate == true))' temp/keymap-noseperatecombos.yaml
yq -i 'del(.combos[] | select(.draw_separate != true))' temp/keymap-onlyseperatecombos.yaml

cp temp/keymap-onlyseperatecombos.yaml temp/keymap-onlyshortcutcombos.yaml
cp temp/keymap-onlyseperatecombos.yaml temp/keymap-onlynavcombos.yaml

yq -i 'del(.combos[] | select(.layers | contains(["shortcuts"]) | not))' temp/keymap-onlyshortcutcombos.yaml
yq -i 'del(.combos[] | select(.layers | contains(["nav"]) | not))' temp/keymap-onlynavcombos.yaml

# Run keymap drawer on generated yaml files
poetry run keymap -c 2column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/whole_keymap.svg

poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/alpha_layers.svg -s alpha1 alpha2
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/numbers_layer.svg -s numbers
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/symbols_layer.svg -s symbols
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/shortcuts_layer.svg -s shortcuts
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/nav_layer.svg -s nav
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/text_layer.svg -s text
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/media_layer.svg -s media
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/function_layer.svg -s func
poetry run keymap -c 1column_config.yaml draw temp/keymap-noseperatecombos.yaml -o svgs/macros_layer.svg -s macros

poetry run keymap -c 2column_config.yaml draw temp/keymap-onlyshortcutcombos.yaml --combos-only -o svgs/shortcut_combos.svg -s shortcuts
poetry run keymap -c 2column_config.yaml draw temp/keymap-onlynavcombos.yaml --combos-only -o svgs/nav_combos.svg -s nav

# Delete extra yaml files
rm -R -f temp

echo -e "\033[34mTask completed at $(date '+%d/%m/%Y %H:%M:%S')\033[0m"
