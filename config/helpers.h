    /* LAYER TAPS */

    #define LAYERTAP_TP(NAME, BINDINGS) \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            bindings = <&mo>, <BINDINGS>; \
        };

    #define LAYERTAP_HP(NAME, BINDINGS) \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "hold-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            bindings = <&mo>, <BINDINGS>; \
        };


    /*  MOD TAPS  */

    #define MODTAP_TP(NAME, BINDINGS) \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            require-prior-idle-ms = <QUICK_TAP_TERM>; \
            bindings = <&kp>, <BINDINGS>; \
        };

    /*  TAP HOLDS  */

    #define TAPHOLD_TP(NAME, TAP, HOLD) \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            require-prior-idle-ms = <QUICK_TAP_TERM>; \
            bindings = <HOLD>, <TAP>; \
        };

    #define TAPHOLD_TP_AGRESSIVE(NAME, TAP, HOLD) \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "tap-preferred"; \
            #binding-cells = <2>; \
            tapping-term-ms = <MINI_TAP_TERM>; \
            quick-tap-ms = <0>; \
            require-prior-idle-ms = <0>; \
            bindings = <HOLD>, <TAP>; \
        };

    /*  HOMEROW MODS  */

    #define HOMEROW(NAME, HOLD, TAP, TRIGGER_POS) \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            flavor = "balanced"; \
            #binding-cells = <2>; \
            tapping-term-ms = <280>; \
            quick-tap-ms = <QUICK_TAP_TERM>; \
            require-prior-idle-ms = <150>; \
            bindings = <HOLD>, <TAP>; \
            hold-trigger-on-release; \
            hold-trigger-key-positions = <TRIGGER_POS>; \
        };

    #define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
        ZMK_HOLD_TAP(NAME, bindings = <HOLD>, <TAP>; flavor = "balanced"; \
               tapping-term-ms = <280>; quick-tap-ms = <QUICK_TAP_TERM>; \
               require-prior-idle-ms = <150>; hold-trigger-on-release; \
               hold-trigger-key-positions = <TRIGGER_POS>;)

    /*  MACROS  */

    #define MACRO(NAME, BINDINGS) \
        NAME: NAME { \
			compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            wait-ms = <5>; \
            tap-ms = <5>; \
            bindings = <BINDINGS>; \
        };

    /*  MOD MORPHS  */

    #define MOD_MORPH(NAME, MODS, MODDED, UNMODDED) \
        NAME: NAME { \
            compatible = "zmk,behavior-mod-morph"; \
            #binding-cells = <0>; \
            bindings = <UNMODDED>, <MODDED>; \
            mods = <(MODS)>; \
        };

    #define MOD_MORPH_KM(NAME, MODS, MODDED, UNMODDED) \
        NAME: NAME { \
            compatible = "zmk,behavior-mod-morph"; \
            #binding-cells = <0>; \
            bindings = <UNMODDED>, <MODDED>; \
            mods = <(MODS)>; \
            keep-mods = <(MODS)>; \
        };

    /*  SHIFT_MORPH  */

    #define SHIFT_MORPH(NAME, UNSHIFTED, SHIFTED) \
        NAME: NAME { \
            compatible = "zmk,behavior-mod-morph"; \
            #binding-cells = <0>; \
            bindings = <UNSHIFTED>, <SHIFTED>; \
            mods = <(MOD_LSFT|MOD_RSFT)>; \
        };

    /*  ACCENTS  */

    #define ACCENT(NAME, KEY, DEAD_KEY) \
        NAME: NAME { \
            wait-ms = <0>; \
            tap-ms = <0>; \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            bindings \
                = <&macro_tap &kp RA(DEAD_KEY)> \
                , <&macro_tap &kp KEY> \
                ; \
        }; \
        NAME##_c: NAME##_c { \
            wait-ms = <0>; \
            tap-ms = <0>; \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            bindings \
                = <&macro_release &kp LSHFT &kp RSHFT> \
                , <&macro_tap &kp RA(DEAD_KEY)> \
                , <&macro_press &kp RSHFT> \
                , <&macro_tap &kp KEY> \
                , <&macro_release &kp RSHFT> \
                ; \
        }; \
        NAME##_s: NAME##_s { \
            wait-ms = <0>; \
            tap-ms = <0>; \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            bindings \
                = <&macro_release &kp LSHFT &kp RSHFT> \
                , <&macro_tap &kp RA(DEAD_KEY)> \
                , <&macro_press &kp LSHFT> \
                , <&macro_tap &kp KEY> \
                , <&macro_release &kp LSHFT> \
                ; \
        };

    /*  COMBOS  */

    #define COMBO(NAME, KEYS, BINDINGS, LAYERS) \
        NAME { \
            timeout-ms = <COMBO_TERM>; \
            layers = <LAYERS>; \
            key-positions = <KEYS>; \
            bindings = <BINDINGS>; \
        };

    #define COMBO_MUST_TAP(NAME, HOLD, TAP) \
        NAME##hold: NAME##hold { \
            compatible = "zmk,behavior-macro"; \
            #binding-cells = <0>; \
            wait-ms = <0>; \
            tap-ms = <0>; \
            bindings \
                = <&macro_press HOLD> \
                , <&macro_pause_for_release> \
                , <&macro_release HOLD> \
                ; \
        }; \
        NAME##tap: NAME##tap {  \
            compatible = "zmk,behavior-macro";  \
            #binding-cells = <0>; \
            wait-ms = <0>; \
            tap-ms = <0>; \
            bindings = <&macro_tap TAP>; \
        }; \
        NAME: NAME { \
            compatible = "zmk,behavior-hold-tap"; \
            #binding-cells = <2>; \
            tapping-term-ms = <TAPPING_TERM>; \
            flavor = "hold-preferred"; \
            bindings = <&NAME##hold>, <&NAME##tap>; \
        };

    /*  ADAPTIVE KEYS  */

    #define ADAPTIVE(NAME, TRIGGERS, BINDINGS) \
        adaptive_##NAME: adaptive_##NAME { \
            trigger-keys = <TRIGGERS>; \
            bindings = <BINDINGS>; \
            max-prior-idle-ms = <ADAPTIVE_KEY_TIMEOUT>; \
        };

    #define ADAPTIVE_STRICT(NAME, TRIGGERS, BINDINGS) \
        adaptive_##NAME: adaptive_##NAME { \
            strict-modifiers; \
            trigger-keys = <TRIGGERS>; \
            bindings = <BINDINGS>; \
            max-prior-idle-ms = <ADAPTIVE_KEY_TIMEOUT>; \
        };

    /*  END  */
