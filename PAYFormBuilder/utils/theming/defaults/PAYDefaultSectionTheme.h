//
//  PAYSectionTheme.h
//  Pods
//
//  Created by COBI on 09.04.15.
//
//

#import <Foundation/Foundation.h>
#import "PAYSectionTheme.h"

@interface PAYDefaultSectionTheme : NSObject <PAYSectionTheme>

@property (nonatomic, assign) CGFloat           horizontalMargin;
@property (nonatomic, assign) CGFloat           labelWidth;
@property (nonatomic, assign) BOOL              fixedLabelWidth;
@property (nonatomic, assign) NSTextAlignment   fieldTextAlignment;
@property (nonatomic, assign) BOOL              fixedSeperatorInset;
@property (nonatomic, assign) UIEdgeInsets      seperatorInset;
@property (nonatomic, assign) CGFloat           labelFieldSpacing;
@property (nonatomic, assign) CGFloat           detailLabelMarginRight;
@property (nonatomic, assign) CGFloat           disclosureMarginRight;
@property (nonatomic, assign) CGFloat           iconSize;
@property (nonatomic, assign) CGFloat           iconMargin;
@property (nonatomic, assign) CGFloat           iconMarginLeft;
@property (nonatomic, assign) NSUInteger        textViewLineCount;
@property (nonatomic, assign) NSUInteger        textViewMaxLineCount;

@property (nonatomic, copy, nullable)   PAYViewProviderBlock detailAccessoryViewProviderBlock;
@property (nonatomic, copy, nullable)   PAYViewProviderBlock checkmarkAccessoryViewProviderBlock;
@property (nonatomic, retain, nullable) UIColor          *textColor;
@property (nonatomic, retain, nullable) UIColor          *errorTextColor;
@property (nonatomic, retain, nullable) UIColor          *disabledTextColor;
@property (nonatomic, retain, nullable) UIColor          *placeholderColor;
@property (nonatomic, retain, nullable) NSMutableDictionary *buttonTextColors;
@property (nonatomic, retain, nullable) UIColor          *buttonDetailTextColor;

@end
