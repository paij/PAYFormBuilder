//
//  PAYFormField.h
//  PAYFormBuilder
//
//  Created by Simon Seyer on 01.11.13.
//  Copyright (c) 2014 Paij. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAYFormView.h"
#import "PAYValidatableFormCell.h"


typedef void(^PAYFormFieldCompletionBlock)(void);
typedef id _Nonnull (^PAYFormFieldFormatBlock)(PAYFormField * _Nonnull, id _Nonnull);
typedef id _Nonnull (^PAYFormFieldCleanBlock)(PAYFormField * _Nonnull, id _Nonnull);
typedef NSError * _Nullable (^PAYFormFieldValidationBlock)(PAYFormField * _Nonnull);


@protocol PAYFormControl;


/**
 *  A form view that contains a view control, the user could interact with.
 */
@interface PAYFormField : PAYFormView <PAYValidatableFormCell, UITextFieldDelegate>

/**
 *  The control that is embedded in this view
 */
@property (nonatomic, retain, readonly, nonnull) UIView<PAYFormControl> *control;

/**
 *  An optional format block that is used to format the value the user entered
 */
@property (nonatomic, copy, nullable) PAYFormFieldFormatBlock formatBlock;

/**
 *  An optional clean block to clean the value the user entered before processing it.
 *  Access this value with the cleanedValue method.
 */
@property (nonatomic, copy, nullable) PAYFormFieldCleanBlock cleanBlock;

/**
 *  A custom validation block for this field. Should return an error, when the field
 *  is not valid. Use the validationErrorWithTitle:message: or validationErrorWithCode:
 *  to create validation warnings for this field.
 */
@property (nonatomic, copy, nullable) PAYFormFieldValidationBlock validationBlock;

/**
 *  Validates, that the control has a value
 */
@property (nonatomic, assign, getter=isRequired) BOOL required;

/**
 *  Specifies if the control is enabled
 */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/**
 *  Get the value the user entered
 *
 *  @return the entered value
 */
- (nonnull id)value;

/**
 *  Get the value the user entered cleaned with the clean block
 *
 *  @return the cleaned value
 */
- (nonnull id)cleanedValue;

/**
 *  If the control has NO value
 *
 *  @return true, if the control has no value, false otherwise
 */
- (BOOL)isEmpty;

/**
 *  Create a validation error for this field with a title and a message
 *
 *  @param title   the title of the error
 *  @param message the description, what the used did wrong
 *
 *  @return an error that for example could be returned in a validation block
 */
- (nonnull NSError *)validationErrorWithTitle:(nonnull NSString *)title
                                      message:(nonnull NSString *)message;

/**
 *  Create a validation error for this field with a an error code.
 *
 *  @param code the code of this error
 *
 *  @return an error that for example could be returned in a validation block
 */
- (nonnull NSError *)validationErrorWithCode:(NSUInteger)code;

@end
